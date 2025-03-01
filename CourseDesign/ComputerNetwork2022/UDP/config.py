"""
This is the global settings for UDP client and server.

The UDP Custom Packet Format is displayed as below:
+ - - - - - - - - - - - - - - - - - - - - - - - - - -  +
+   seq   | version |  SYN  |  FIN  |      content     +
+ -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - +
+ 2 bytes | 1 byte  | 1 bit | 1 bit |   MAX 198 Bytes  +
+ - - - - - - - - - - - - - - - - - - - - - - - - - -  +

Demonstration:
- seq:     sequence number -- the unique identifier of one client-server connection. 2 bytes long.
- version: version number -- Default to decimal number `2`.
- SYN:     The same as that in TCP packet. Used in establishing connection.
- FIN:     The same as that in TCP packet. Used in closing connection.
- content: The actual message. 198 bytes maximum.

You may change either part in the structure if you prefer.

"""


class Settings:
    # IP addr & Port
    PORT = 8000
    IP = "127.0.0.1"

    # Basic data format
    SEQ_NUM = 2
    VER_NUM = 1
    SYN_BIT = 1
    FIN_BIT = 1
    CONTENT = 198
    FORMAT = "utf-8"

    BUFF_SIZE = SEQ_NUM + VER_NUM + CONTENT

    # Loss rate
    LOSS = 0.05

    # Fin ACK
    FIN_ACK = "acknowledged".upper()

    # Total packets to send
    PACKETS = 12
