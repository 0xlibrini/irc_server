#include "../includes/Server.hpp"
#include "../includes/ft_irc.hpp"

void Server::USER_cmd(int fd, const Command &cmd)
{
    Client *client;
    client = _clients[fd];
    std::string target = client->getNick().empty() ? "*" : client->getNick();
    if (client->isRegistered())
    {
        sendReply(fd, ":irc.server " + std::string(ERR_ALREADYREGISTRED) + " " + target + " :You may not reregister\r\n");
        return;
    }
    if (cmd.getParams().size() < 4)
    {
        sendReply(fd, ":irc.server " + std::string(ERR_NEEDMOREPARAMS) + " " + target + " USER :Not enough parameters\r\n");
        return;
    }
    client->setUser(cmd.getParams()[0]);
    client->setRealName(cmd.getParams()[3]);
    if (registerClient(client))
    {
        std::cout << "USER executed for fd=" << fd << std::endl;
    }
}
