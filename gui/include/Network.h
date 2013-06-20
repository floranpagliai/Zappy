#ifndef NETWORK_H
#define	NETWORK_H

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "error.h"
#include "MyGame.h"
#include "Parseur.h"

#define	fldoff(name, field) \
	((int)&(((struct name *)0)->field))

/* Size of the field in the structure. */
#define	fldsiz(name, field) \
	(sizeof(((struct name *)0)->field))

/* Address of the structure from a field. */
#define	strbase(name, addr, field) \
	((struct name *)((char *)(addr) - fldoff(name, field)))

#define		BUF_MAX	1024

typedef struct {
    struct protoent *pe;
    struct sockaddr_in sin;
    int s;
    int cs;
    fd_set fd_r;
    fd_set fd_w;
    int pos;
    char buf[BUF_MAX];
    int buf_ok;
} t_client;

class Network {
private:
    MyGame *game_;
    Parseur parseur_;
    int port_;
    char *ip_;
    t_client client_;

public:
    Network();
    virtual ~Network();

    void initClient(int port, char *ip, MyGame *);

    int getData();
    int check_socket();
    void do_client();

    void sendData(char *);
};

#endif	/* NETWORK_H */

