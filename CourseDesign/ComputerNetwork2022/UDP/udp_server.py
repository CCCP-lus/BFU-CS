import socket
import random
import datetime
import argparse
import threading

from typing import Tuple

from config import Settings
from util import CustomArgParser


class UDPServer:
    def __init__(self, server_ip: str = Settings.IP, server_port: int = Settings.PORT):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.server.bind((server_ip, server_port))

    # Determine whether to drop an incoming packet
    @staticmethod
    def __emulate_loss() -> bool:
        return random.random() >= Settings.LOSS

    # Decode the message and send the reply
    def _handle_client(self, msg: bytes, addr: Tuple[str, int]):
        def pad_string(s: str) -> str:
            if len(s) < Settings.CONTENT:
                return "".join([s, " " * (Settings.CONTENT - len(s))])
            return s[Settings.CONTENT]

        curr_time = datetime.datetime.now().timestamp()

        msg = msg.decode(Settings.FORMAT)
        seq, ver, syn, fin, _ = (
            msg[: Settings.SEQ_NUM],
            msg[Settings.SEQ_NUM : (Settings.SEQ_NUM + Settings.VER_NUM)],
            int(msg[Settings.SEQ_NUM + Settings.VER_NUM]),
            int(msg[Settings.SYN_BIT + Settings.SEQ_NUM + Settings.VER_NUM]),
            msg[
                (
                    Settings.FIN_BIT
                    + Settings.SYN_BIT
                    + Settings.SEQ_NUM
                    + Settings.VER_NUM
                ) : :
            ].strip(),
        )

        if syn:
            msg_to_send = "".join(
                [seq, ver, str(syn), str(fin), pad_string(str(curr_time))]
            ).encode(Settings.FORMAT)
        elif fin:
            msg_to_send = "".join(
                [
                    seq,
                    ver,
                    str(syn),
                    str(fin),
                    pad_string(str(curr_time) + Settings.FIN_ACK),
                ]
            ).encode(Settings.FORMAT)
        else:
            msg_to_send = "".join(
                [seq, ver, str(syn), str(fin), pad_string(str(curr_time))]
            ).encode(Settings.FORMAT)

        self.server.sendto(msg_to_send, addr)
        print("Message sent:", msg_to_send)

        return fin == 1

    def run(self) -> None:
        print(f"Server starts at [IP: {Settings.IP}] and [Port: {Settings.PORT}]")
        while True:
            msg, addr = self.server.recvfrom(Settings.BUFF_SIZE)

            print("Message received:", msg)
            if UDPServer.__emulate_loss():
                client = threading.Thread(target=self._handle_client, args=(msg, addr))
                client.start()
                client.join()


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

    parser.add_argument(
        "-lo",
        "--loss",
        type=CustomArgParser.float_in_range,
        default=0.05,
        help="Customize the loss rate for server",
    )

    args = parser.parse_args()
    Settings.IP = args.serverIP
    Settings.PORT = args.serverPort
    Settings.LOSS = args.loss

    server = UDPServer(Settings.IP, Settings.PORT)
    server.run()
