# UDP Emulation

## Quick Start

1. Make sure you have `virtualenv` installed in your local Python environment. If you're not sure or it does not exist, install it with:

   ```bash
   pip install virtualenv
   ```

2. Clone this repo into your local machine.

   ```bash
   git clone https://github.com/Computer-Network-Class-Design/UDP.git
   ```

3. Open this cloned repo with VsCode. Then under it's integrated terminal, create a virtual environment with the following command.

   ```bash
   virtualenv env
   ```

4. Activate virtual environment.

   In MacOS system, type in `source env/bin/activate`.

   In Windows system, type in `.\env\Scripts\activate.ps1`.

5. Install requirements.

   ```bash
   pip install -r requirements.txt
   ```

## Server

The udp server can be started in the following ways.

| Verbose Commands                            | Brief Commands                        | Demonstration                                 |
| ------------------------------------------- | ------------------------------------- | --------------------------------------------- |
| `python -m udp_server --serverIP=localhost` | `python -m udp_server -sip=localhost` | To start the server with specific IP address  |
| `python -m udp_server --serverPort=8000`    | `python -m udp_server -spt=8000`      | To start the server with specific port number |
| `python -m udp_server --loss=0.2`           | `python -m udp_server -lo=0.2`        | To start the server with specific loss rate   |

Of course, you can combine **any** / **all** / **none** of the commands above to initialize the server socket.

> If you choose to exclude all parameters, the server will run with default settings, i.e. `serverIP=127.0.0.1` & `serverPort=8000` & `loss=0.05`.

## Client

The udp client class offers flexible choices to configure as you like.

| Verbose Commands                            | Brief Commands                        | Demonstration                                         |
| ------------------------------------------- | ------------------------------------- | ----------------------------------------------------- |
| `python -m udp_client --serverIP=localhost` | `python -m udp_client -sip=localhost` | To initialize the client with a specific IP address.  |
| `python -m udp_client --serverPort=8000`    | `python -m udp_client -spt=8000`      | To initialize the client with a specific Port number. |
| `python -m udp_client --timeout=0.2`        | `python -m udp_client -t=0.2`         | Set timeout for client to receive responses.          |
| `python -m udp_client --retry=2`            | `python -m udp_client -r=2`           | Set maximum retries if the server does not respond.   |

Of course, you can combine **any** / **all** / **none** of the commands above to fully customize your client socket.

> If you choose to exclude all parameters, the client will run with default settings, i.e. `serverIP=127.0.0.1` & `serverPort=8000` & `timeout=0.1` & `retry=2`.
