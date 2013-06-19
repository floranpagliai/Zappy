#include "MyGame.h"

int main(int ac, char** av) {
    MyGame game;
    if (ac == 3) {
        game.initNetwork(atoi(av[2]), av[1]);
        game.run();
    }
    return (EXIT_SUCCESS);
}

