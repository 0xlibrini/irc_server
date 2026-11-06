#include "includes/Server.hpp"

int main(int ac , char **av)
{   
    if(ac != 3) { std::cout << "Usage ./ircserv <port> <password>." << std::endl; return EXIT_FAILURE;}
    if(validPort(av[1])) {std::cout << "Wrong Port Number." << std::endl; return EXIT_FAILURE;}

    Server server(std::atoi(av[1]) , av[2]);

    try { server.StartServer();}
    catch(std::runtime_error &e) {std::cout << e.what()  << std::endl;}
}
