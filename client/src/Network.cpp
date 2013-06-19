/*
 * File:   Network.cpp
 * Author: floran
 *
 * Created on 19 juin 2013, 14:21
 */

#include "Network.h"

Network::Network(int port, char *ip, t_client *client) {
    this->port_ = port;
    this->ip_ = ip;
    this->client_ = client;
    this->initClient();
}

Network::Network(const Network& orig) {
}

Network::~Network() {
    close(this->client_->s);
}

void Network::initClient() {
    this->client_->pe = getprotobyname("TCP");
    if ((this->client_->s = socket(AF_INET, SOCK_STREAM, this->client_->pe->p_proto)) == -1)
        //error(ERROR_SOCKET);
        std::cout << "error" << std::endl;
    this->client_->sin.sin_family = AF_INET;
    this->client_->sin.sin_port = htons(port);
    if ((int) (this->client_->sin.sin_addr.s_addr = inet_addr(ip)) == -1)
        //error("error");
        std::cout << "error" << std::endl;
    this->client_->pos = 0;
    this->client_->buf_ok = 0;
}
