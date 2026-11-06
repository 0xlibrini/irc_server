NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp srcs/Server.cpp srcs/Client.cpp srcs/Channel.cpp srcs/Command.cpp srcs/server_commands.cpp srcs/helpers.cpp cmds/PRIVMSG.cpp cmds/TOPIC.cpp cmds/JOIN.cpp cmds/PART.cpp cmds/NICK.cpp cmds/KICK.cpp cmds/USER.cpp cmds/MODE.cpp cmds/INVITE.cpp cmds/PASS.cpp cmds/CAP.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
