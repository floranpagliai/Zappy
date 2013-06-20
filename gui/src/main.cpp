#include "MyGame.h"
#include "Network.h"

Network network;
MyGame game;

static void *task_a(void *p_data) {
    (void) p_data;
    network.do_client();
    return NULL;
}

static void *task_b(void *p_data) {
    (void) p_data;
    game.run();
    return NULL;
}

int main(int ac, char** av) {
    pthread_t ta;
    pthread_t tb;
    if (ac == 3) {
        network.initClient(atoi(av[1]), av[2], &game);
        pthread_create(&ta, NULL, task_a, NULL);
        pthread_create(&tb, NULL, task_b, NULL);

        pthread_join(ta, NULL);
        pthread_join(tb, NULL);
    } else
        std::cout << "[USAGE] : (port) (hote)" << std::endl;

    return 0;
}