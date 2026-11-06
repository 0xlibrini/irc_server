
*This project has been created as part of the 42 curriculum by **elel-m-b**, **mbrouk**, **anlibrin**.*

---

#  Description

**ft_irc** is a custom implementation of an **Internet Relay Chat (IRC) server** written in **C++98** as part of the 42 curriculum.

The objective of this project is to understand how IRC works internally by implementing a server that follows the IRC protocol (RFC 1459 / RFC 2812 concepts). The server allows multiple clients to connect simultaneously, authenticate, join channels, communicate, and manage channels using IRC commands.

The server is designed to work with standard IRC clients such as **irssi**, allowing real-world testing without modifying the client.

---

##  Main Features

-  IRC server implemented in C++98
-  Non-blocking sockets
-  Single `poll()` event loop
-  Multiple simultaneous clients
-  Password authentication
-  User registration (`PASS`, `NICK`, `USER`)
-  Channel creation and management
-  Private messaging
-  Channel messaging
-  Operator privileges
-  Channel modes
-  Compatible with standard IRC clients (e.g. irssi)

---

#  Mandatory Commands

##  Registration

- PASS
- NICK
- USER

---

##  Communication

- PRIVMSG

---

##  Channels

- JOIN
- PART
- TOPIC
- INVITE
- KICK

---

##  Operators

- MODE

---

##  Project Structure

```text
.
├── bot/
├── cmds/
├── includes/
├── srcs/
├── main.cpp
├── Makefile
├── README.md
└── ...
```

---

#  Instructions

##  Clone the repository

```bash
git clone git@github.com:elel-m-b/IRC-Server.git
cd ft_irc
```

---

##  Compile

```bash
make
```

This generates the executable:

```text
ircserv
```

---

##  Run the server

```bash
./ircserv <port> <password>
```

Example:

```bash
./ircserv 6667 mypassword
```

---

#  Connecting with irssi

Install irssi:

Ubuntu:

```bash
sudo apt install irssi
```

Start irssi:

```bash
irssi
```

Connect to the server:

```text
/connect 127.0.0.1 6667 mypassword
```

Choose a nickname:

```text
/nick alice
```

Join a channel:

```text
/join #general
```

Send a message:

```text
Hello everyone!
```

---

#  Example with netcat

You can also test the server manually.

```bash
nc -C 127.0.0.1 6667
```

Example registration:

```text
PASS mypassword
NICK alice
USER alice 0 * :Alice
```

---

#  Channel Modes

The server supports the mandatory channel modes required by the subject:

| Mode | Description |
|:----:|-------------|
| `i` | Invite-only channel |
| `t` | Only operators can change the topic |
| `k` | Password protected channel |
| `o` | Give/remove operator privileges |
| `l` | User limit |

---

---

#  Resources

##  IRC Documentation
  - https://medium.com/@mohcin.ghalmi/irc-server-internet-relay-chat-bd08e4f469f8
  - https://medium.com/@mohamedsarda/ft-irc-channels-and-command-management-ff1ff3758a0b
  - https://www.alien.net.au/irc/irc2numerics.html
  - https://modern.ircdocs.horse/
---

##  Linux Documentation

man pages

- man socket
- man bind
- man listen
- man accept
- man connect
- man recv
- man send
- man poll

---

##  IRC Client

irssi

https://irssi.org/

---

#  AI Usage

Artificial Intelligence tools (ChatGPT) were used throughout the development of this project as a learning and productivity aid.

AI assistance included:

- Understanding socket programming and networking concepts.
- Explaining system calls such as `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `recv()`, `send()`, and `poll()`.

All architecture decisions, implementation, debugging, testing, and final source code were designed, written, and validated by the project authors.

---

#  Authors

- **elel-m-b**
- **mbrouk**
- **anlibrin**

---

#  License

This project was developed for educational purposes as part of the **42 School** curriculum.

---
