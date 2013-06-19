/*
 * File:   Network.cpp
 * Author: floran
 *
 * Created on 19 juin 2013, 14:21
 */

#include "Network.h"

Network::Network() {
    t_client client;
    this->client_ = client;
    std::cout << "constructeur network" << std::endl;
}

Network::~Network() {
    close(this->client_.s);
}

void Network::initClient(int port, char *ip) {
    this->port_ = port;
    this->ip_ = ip;

    this->client_.pe = getprotobyname("TCP");
    if ((this->client_.s = socket(AF_INET, SOCK_STREAM, this->client_.pe->p_proto)) == -1)
        error(ERROR_SOCKET);
    this->client_.sin.sin_family = AF_INET;
    this->client_.sin.sin_port = htons(this->port_);
    if ((int) (this->client_.sin.sin_addr.s_addr = inet_addr(this->ip_)) == -1)
        error("error");
    this->client_.pos = 0;
    this->client_.buf_ok = 0;
}

void Network::check_stdin() {
    int i;

    if (FD_ISSET(0, &(this->client_.fd_r))) {
        i = read(0, &(this->client_.buf[this->client_.pos]),
                BUF_MAX - 1 - this->client_.pos);
        if (i > 0) {
            this->client_.pos += i;
            this->client_.buf[this->client_.pos] = 0;
            this->client_.buf_ok = 1;
        }
    }
}

int Network::get_data() {
    int i;
    char buf[512];

    i = read(this->client_.s, buf, 512);
    if (i <= 0) {
        fprintf(stderr, "Connexion close.\n");
        return (-1);
    }
    write(1, buf, i);
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
        i = get_data();
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
    std::cout << "1" << std::endl;
    if ((this->client_.cs = connect(this->client_.s,
            (struct sockaddr *) &(this->client_.sin),
            sizeof (struct sockaddr_in))) == -1)
        error(ERROR_CONNECT);
    std::cout << "2" << std::endl;
    while (ok != -1) {
        std::cout << "3" << std::endl;
        FD_ZERO(&(this->client_.fd_r));
        FD_ZERO(&(this->client_.fd_w));
        FD_SET(0, &(this->client_.fd_r));
        FD_SET(this->client_.s, &(this->client_.fd_r));
        if (this->client_.buf_ok)
            FD_SET(this->client_.s, &(this->client_.fd_w));
        if ((ok = select(this->client_.s + 1, &(this->client_.fd_r),
                &(this->client_.fd_w), NULL, NULL)) != -1) {
            check_stdin();
            ok = check_socket();
        }
    }
}