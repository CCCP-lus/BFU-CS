import socket
import string
import random
import argparse
import statistics

from util import Retry, SeqID
from config import Settings

characters = string.ascii_letters + string.digits
retry = Retry(timeout=0.1, retry=2)


class UDPClient:
    def __init__(self, server_ip: str = Settings.IP, server_port: int = Settings.PORT):
        SeqID.reset()  # Reset the sequence number

        self.server_addr = (server_ip, server_port)
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        self.packets_received = 0
        self.packets_to_send = 0
        self.round_trip_time = []
        self.initial_response = self.final_response = None

    # A wrapper for generating the next sequence number
    def _generate_seq(self) -> str:
        return next(SeqID())

    # A utility function for generating ver number
    def _generate_ver(self) -> str:
        return "0" * (Settings.VER_NUM - 1) + "2"

    # A utility function for generating random content
    def _generate_random_content(self) -> str:
        return "".join(random.choice(characters) for _ in range(Settings.CONTENT))

    # A utility function for generating the actual message to send
    def _generate_msg(self, syn: bool, fin: bool):
        msg_to_send = [
            self._generate_seq(),
            self._generate_ver(),
            "0",
            "0",
            self._generate_random_content(),
        ]

        if syn:
            msg_to_send[2] = "1"
        if fin:
            msg_to_send[3] = "1"

        return "".join(msg_to_send)

    # The actual send method (With timeout decorator)
    @retry.timeout()
    def send(self, syn: bool = False, fin: bool = False, **retry_msg) -> str:
        msg_to_send = retry_msg.get("resend", None)
        if not msg_to_send:
            msg_to_send = self._generate_msg(syn, fin).encode(Settings.FORMAT)
        self.client.sendto(msg_to_send, self.server_addr)

        self.client.settimeout(retry._timeout)
        try:
            msg, _ = self.client.recvfrom(Settings.BUFF_SIZE)
            msg = msg.decode(Settings.FORMAT)
        except socket.timeout:
            msg = None

        return msg, msg_to_send

    # Display useful info
    def dump(self):
        print("Packets Received:".ljust(25), self.packets_received)
        print(
            "Packets Loss:".ljust(25),
            f"{(1 - self.packets_received / self.packets_to_send) * 100}%",
        )

        if self.round_trip_time:
            print("Max  RTT:".ljust(25), f"{max(self.round_trip_time)}s")
            print("Min  RTT:".ljust(25), f"{min(self.round_trip_time)}s")
            print(
                "Mean RTT:".ljust(25),
                f"{sum(self.round_trip_time) / len(self.round_trip_time)}s",
            )
        else:
            print("Max  RTT:".ljust(25), "No VALID data!")
            print("Min  RTT:".ljust(25), "No VALID data!")
            print("Mean RTT:".ljust(25), "No VALID data!")

        if len(self.round_trip_time) > 1:
            print(
                "Standard RTT Deviation:".ljust(25),
                f"{statistics.stdev(self.round_trip_time)}s",
            )
        else:
            print("Not enough data to support standard deviation calculation!")

        if self.initial_response and self.final_response:
            print(
                "Server Response:".ljust(25),
                f"{self.final_response - self.initial_response}s",
            )
        else:
            print(
                "Server Response:".ljust(25), "Infinite (due to extreme packet loss)."
            )

    def run(self):
        print("Client starts.")
        try:
            self.send(syn=True, fin=False)
        except ConnectionAbortedError:
            self.client.close()
            return

        for _ in range(Settings.PACKETS):
            self.send()

        self.send(syn=False, fin=True)

        self.client.close()
        self.dump()


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
        "-t", "--timeout", type=float, default=0.1, help="Timeout duration in seconds"
    )
    parser.add_argument(
        "-r", "--retry", type=int, default=2, help="Number of retry attempts"
    )

    args = parser.parse_args()

    server_ip = args.serverIP
    server_port = args.serverPort

    retry._timeout = args.timeout
    retry._retry = args.retry

    client = UDPClient(server_ip, server_port)
    client.run()
