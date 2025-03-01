import time
import re
import argparse

from typing import Callable
from config import Settings

pattern = re.compile(r"^\d+(\.\d+)*")


class SeqID:
    """
    This class implements an iterator such that by calling next(SeqID),
    a new sequence number is returned.
    """

    seq = 0

    @classmethod
    def reset(cls):
        cls.seq = 0

    def __iter__(self):
        return self

    @staticmethod
    def __format(seq_id: int):
        str_seq_id = str(seq_id)
        if len(str_seq_id) < Settings.SEQ_NUM:
            return "0" * (Settings.SEQ_NUM - len(str_seq_id)) + str_seq_id
        return str_seq_id

    def __next__(self):
        curr = SeqID.seq
        SeqID.seq += 1
        return SeqID.__format(curr)


class Retry:
    """
    This class intends to include multiple retry mechanism (it's only timeout for now).
    """

    def __init__(self, timeout: float = 0.1, retry: int = 2):
        self._timeout = timeout
        self._retry = retry

    def timeout(self):
        def decorator(original_function: Callable):
            def wrapper(*args, **kwargs):
                client = args[0]

                msg, resend = None, None
                retry_count = self._retry + 1

                while retry_count > 0 and not msg:
                    start = time.time()
                    msg, send = original_function(*args, **kwargs, resend=resend)
                    if not resend:
                        resend = send
                    end = time.time()

                    retry_count -= 1

                client.packets_to_send += self._retry - retry_count + 1

                if msg:
                    client.packets_received += 1
                    client.round_trip_time.append(end - start)

                    server_time = float(
                        pattern.match(
                            msg[
                                Settings.FIN_BIT
                                + Settings.SYN_BIT
                                + Settings.SEQ_NUM
                                + Settings.VER_NUM : :
                            ]
                        ).group(0)
                    )

                    if not client.initial_response:
                        client.initial_response = server_time
                    client.final_response = server_time

                    print("Sequence No:".ljust(15), send[: Settings.SEQ_NUM])
                    print("Server IP:".ljust(15), client.server_addr[0])
                    print("Server Port:".ljust(15), client.server_addr[1])
                    print("RTT:".ljust(15), end - start)
                else:
                    print(
                        "Sequence No:".ljust(15),
                        send[: Settings.SEQ_NUM],
                        "Request time out.",
                    )
                    if send[: Settings.SEQ_NUM] == b"0" * (Settings.SEQ_NUM):
                        raise ConnectionAbortedError("SYN not responded")
                print("- " * 16)

                return msg

            return wrapper

        return decorator


class CustomArgParser:
    @staticmethod
    def float_in_range(value: str):
        try:
            number = float(value)
        except ValueError:
            raise argparse.ArgumentTypeError(f"{value} is not a valid float")

        if not (0 <= number <= 1.0):
            raise argparse.ArgumentTypeError(f"{value} is out of range (0.0 to 1.0)")

        return number
