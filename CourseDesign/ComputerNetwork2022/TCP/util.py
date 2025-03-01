"""
We define the following 4 kinds of packets.

 Type 1 -- Initialization     Type 2 -- Agree
+ - - - - - - - - - - - - +   + - - - - - - +
+ Type (Enum) |     N     +   + Type (Enum) +
+ -  -  -  -  -  -  -  -  +   + -  -  -  -  +
+  2 bytes    |  4 bytes  +   +   2 bytes   +
+ - - - - - - - - - - - - +   + - - - - - - +

          Type 3 -- reverseRequest
+ - - - - - - - - - - - - + - - - - - - - - +
+ Type (Enum) |  Length   |       Data      |
+ -  -  -  -  -  -  -  -  -  -  -  -  -  -  +
+  2 bytes    |  4 bytes  |     No Limit    |
+ - - - - - - - - - - - - + - - - - - - - - +

          Type 4 -- reverseAnswer
+ - - - - - - - - - - - - + - - - - - - - - +
+ Type (Enum) |  Length   |   reversedData  |
+ -  -  -  -  -  -  -  -  -  -  -  -  -  -  +
+  2 bytes    |  4 bytes  |     No Limit    |
+ - - - - - - - - - - - - + - - - - - - - - +
"""

import argparse

from enum import Enum
from typing import Tuple
from config import Settings


class PacketType(Enum):
    """
    An enum class holding multiple types of packets
    """

    initialize = 1
    agreement = 2
    reverse_req = 3
    reverse_ans = 4


class CustomPackets:
    """
    This class is responsible for both encoding and decoding the above four types of packets
    """

    @staticmethod
    def __format(val: int, length: int) -> str:
        str_val = str(val)
        if len(str_val) < length:
            return "0" * (length - len(str_val)) + str_val

    def __init__(self, packet_type: PacketType):
        self.__type = packet_type
        self.packet_type = CustomPackets.__format(packet_type.value, Settings.TYPE_NUM)

    def generate_packet_bytes(self, *, N=None, length=None, data=None) -> bytes:
        if self.__type == PacketType.initialize:
            msg_to_send = (
                f"{self.packet_type}{CustomPackets.__format(N, Settings.LEN_OR_N)}"
            )
        if self.__type == PacketType.agreement:
            msg_to_send = self.packet_type
        if (
            self.__type == PacketType.reverse_req
            or self.__type == PacketType.reverse_ans
        ):
            msg_to_send = f"{self.packet_type}{CustomPackets.__format(length, Settings.LEN_OR_N)}{data}"

        return msg_to_send.encode(Settings.FORMAT)

    def decode_from_bytes(
        self, data: bytes
    ) -> Tuple[int] | Tuple[int, int] | Tuple[int, int, int]:
        decoded_data = data.decode(Settings.FORMAT)
        if not decoded_data:
            raise ConnectionAbortedError("Unexpected client exit")

        type_num = int(decoded_data[: Settings.TYPE_NUM])

        if self.__type == PacketType.agreement:
            return (type_num,)
        if self.__type == PacketType.initialize:
            N = int(
                decoded_data[
                    Settings.TYPE_NUM : (Settings.TYPE_NUM + Settings.LEN_OR_N)
                ]
            )
            return (type_num, N)

        if (
            self.__type == PacketType.reverse_req
            or self.__type == PacketType.reverse_ans
        ):
            length = int(
                decoded_data[
                    Settings.TYPE_NUM : (Settings.TYPE_NUM + Settings.LEN_OR_N)
                ]
            )
            raw_data = decoded_data[(Settings.TYPE_NUM + Settings.LEN_OR_N) :]

            return (type_num, length, raw_data)


class CustomArgParser:
    @staticmethod
    def int_within_range(val: str) -> int:
        try:
            int_val = int(val)
        except ValueError:
            raise argparse.ArgumentTypeError(f"{val} is not a valid integer.")

        if int_val <= 0:
            raise argparse.ArgumentTypeError(f"{int_val} should be at least 1.")

        return int_val
