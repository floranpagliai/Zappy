#include "Network.h"

int main(int ac, char** av) {
    Network network;
    if (ac == 3) {
        network.initClient(atoi(av[1]), av[2]);
        network.do_client();
    } else
        std::cout << "[USAGE] : (port) (hote)" << std::endl;

    return 0;
}