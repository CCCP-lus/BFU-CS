# TCP Emulation

## Quick Start

1. Make sure you have `virtualenv` installed in your local Python environment. If you're not sure or it does not exist, install it with:

   ```bash
   pip install virtualenv
   ```

2. Clone this repo into your local machine.

   ```bash
   git clone https://github.com/Computer-Network-Class-Design/TCP.git
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

The tcp server can be started in the following ways.

| Verbose Commands                            | Brief Commands                        | Demonstration                                  |
| ------------------------------------------- | ------------------------------------- | ---------------------------------------------- |
| `python -m tcp_server --serverIP=localhost` | `python -m tcp_server -sip=localhost` | To start the server with specific IP address.  |
| `python -m tcp_server --serverPort=8000`    | `python -m tcp_server -spt=8000`      | To start the server with specific port number. |

Of course, you can combine **any** / **all** / **none** of the commands above to initialize the server socket.

> If you choose to exclude all parameters, the server will run with default settings, i.e. `serverIP=127.0.0.1` & `serverPort=8000`.

## Client

The tcp client class offers a variety of choices to configure as you like.

| Verbose Commands                            | Brief Commands                        | Demonstration                                         |
| ------------------------------------------- | ------------------------------------- | ----------------------------------------------------- |
| `python -m tcp_client --serverIP=localhost` | `python -m tcp_client -sip=localhost` | To initialize the client with a specific IP address.  |
| `python -m tcp_client --serverPort=8000`    | `python -m tcp_client -spt=8000`      | To initialize the client with a specific Port number. |
| `python -m tcp_client --minBytes=10`        | `python -m tcp_client -min=10`        | Set minimum bytes to split the file.                  |
| `python -m tcp_client --maxBytes=20`        | `python -m tcp_client -max=20`        | Set maximum bytes to split the file.                  |

Of course, you can combine **any** / **all** / **none** of the commands above to fully customize your client socket.

> If you choose to exclude all parameters, the client will run with default settings, i.e. `serverIP=127.0.0.1` & `serverPort=8000` & `minBytes=1` & `maxBytes=1e9`.
