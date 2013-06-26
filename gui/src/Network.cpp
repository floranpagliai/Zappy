#include "Network.h"

Network::Network() {
    t_client client;
    this->client_ = client;
}

Network::~Network() {
    close(this->client_.s);
}

void Network::initClient(int port, char *ip, MyGame *game) {
    this->port_ = port;
    this->ip_ = ip;
    this->game_ = game;

    this->client_.pe = getprotobyname("TCP");
    if ((this->client_.s = socket(AF_INET, SOCK_STREAM, this->client_.pe->p_proto)) == -1)
        error(ERROR_SOCKET);
    this->client_.sin.sin_family = AF_INET;
    this->client_.sin.sin_port = htons(this->port_);
    if ((int) (this->client_.sin.sin_addr.s_addr = inet_addr(this->ip_)) == -1)
        error("error");
    this->client_.pos = 0;
    this->client_.buf_ok = 0;
    if ((this->client_.cs = connect(this->client_.s, (struct sockaddr *) &(this->client_.sin), sizeof (struct sockaddr_in))) == -1)
        error(ERROR_CONNECT);
    this->sendData((char*)"GRAPHIC\n");
}

int Network::getData() {
    int ret;
    char buf[2048];
    std::string buffer;

    ret = read(this->client_.s, buf, 2048);
    if (ret <= 0) {
        fprintf(stderr, "Connexion close.\n");
        return (-1);
    }
    buffer = buf;
    this->parseur_.parse(buffer, this->game_);
    this->parseur_.interpret(this->game_);
    return (0);
}

int Network::check_socket() {
    int i;

    if (FD_ISSET(this->client_.s, &(this->client_.fd_r))) {
        if (FD_ISSET(0, &(this->client_.fd_r))) {
            i = read(0, &(this->client_.buf[this->client_.pos]),
                    BUF_MAX - 1 - this->client_.pos);
            this->client_.pos += i;
            this->client_.buf[this->client_.pos] = 0;
        }
        i = getData();
        write(1, this->client_.buf, this->client_.pos);
        return (i);
    }
    if (FD_ISSET(this->client_.s, &(this->client_.fd_w))) {
        write(this->client_.s, this->client_.buf, this->client_.pos);
        this->client_.buf_ok = 0;
        this->client_.pos = 0;
    }
    return (0);
}

void Network::do_client() {
    int ok;

    ok = 1;
    while (ok != -1) {
        FD_ZERO(&(this->client_.fd_r));
        FD_ZERO(&(this->client_.fd_w));
        FD_SET(0, &(this->client_.fd_r));
        FD_SET(this->client_.s, &(this->client_.fd_r));
        if (this->client_.buf_ok)
            FD_SET(this->client_.s, &(this->client_.fd_w));
        if ((ok = select(this->client_.s + 1, &(this->client_.fd_r), &(this->client_.fd_w), NULL, NULL)) != -1) {
            ok = check_socket();
        }
    }
}

void Network::sendData(char *msg) {
    if (send(this->client_.s, msg, strlen(msg), 0) < 0) {
        error(ERROR_WRITE);
    }
}