import socket
import argparse
import threading

from config import Settings
from util import PacketType, CustomPackets


class TCPServer:
    def __init__(self, server_ip: str = Settings.IP, server_port: int = Settings.PORT):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((server_ip, server_port))

        with open(Settings.FILE_NAME, "r") as file:
            self.original_file = file.read()

    def _send_agreement(self, conn: socket.socket):
        initialize = CustomPackets(PacketType.initialize)
        agreement = CustomPackets(PacketType.agreement)

        info = initialize.decode_from_bytes(
            conn.recv((Settings.TYPE_NUM + Settings.LEN_OR_N))
        )
        self.blocks_to_send = info[-1]

        conn.send(agreement.generate_packet_bytes())

    def _process_raw_data(self, conn: socket.socket):
        reverse_req = CustomPackets(PacketType.reverse_req)
        reverse_ans = CustomPackets(PacketType.reverse_ans)

        for _ in range(self.blocks_to_send):
            info = conn.recv(
                (Settings.TYPE_NUM + Settings.LEN_OR_N) + len(self.original_file)
            )

            print(info)

            try:
                _, length, data = reverse_req.decode_from_bytes(info)
            except ConnectionAbortedError as e:
                print(str(e))
                break
            else:
                reversed_data = data[::-1]
                conn.send(
                    reverse_ans.generate_packet_bytes(length=length, data=reversed_data)
                )

    def _handle_client(self, conn: socket.socket):
        self._send_agreement(conn)
        self._process_raw_data(conn)

    def run(self):
        print("Server starts")
        self.server.listen()

        while True:
            conn, _ = self.server.accept()
            thread = threading.Thread(target=self._handle_client, args=(conn,))
            thread.start()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-sip",
        "--serverIP",
        type=str,
        default="127.0.0.1",
        help="The IP address of the server",
    )

    parser.add_argument(
        "-spt", "--serverPort", type=int, default=8000, help="The port of the server"
    )

    args = parser.parse_args()
    Settings.IP = args.serverIP
    Settings.PORT = args.serverPort

    server = TCPServer(Settings.IP, Settings.PORT)
    server.run()
