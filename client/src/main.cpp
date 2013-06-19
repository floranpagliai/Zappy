#include "MyGame.h"

int main(int ac, char** av) {
    t_client client;
    MyGame game;
    if (ac == 3) {
        game.initNetwork(atoi(av[2]), av[1], &client);
        //do_client(&client);
        //client_close(&client);
    }
    game.run();
    return (EXIT_SUCCESS);
}

