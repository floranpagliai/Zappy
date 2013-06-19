#include "MyGame.h"

int main(int ac, char** av) {
    MyGame game;
    if (ac == 3) {
        game.connect(atoi(av[1]), av[2]);
        game.run();
    } else
        std::cout << "[USAGE] : (port) (hote)" << std::endl;
    return (EXIT_SUCCESS);
}