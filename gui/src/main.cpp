#include "MyGame.h"
#include "Network.h"

Network network;
MyGame game;

static void *tnetwork(void *p_data) {
    (void) p_data;
    network.do_client();
    return NULL;
}

static void *tgame(void *p_data) {
    (void) p_data;
    game.run();
    return NULL;
}

int main(int ac, char** av) {
    if (ac == 3) {
        pthread_t tn;
        pthread_t tg;

        network.initClient(atoi(av[1]), av[2], &game);
        pthread_create(&tn, NULL, tnetwork, NULL);
        pthread_create(&tg, NULL, tgame, NULL);

        pthread_join(tg, NULL);
        pthread_join(tn, NULL);

    } else
        std::cout << "[USAGE] : (port) (hote)" << std::endl;

    return 0;
}