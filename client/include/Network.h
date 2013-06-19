#ifndef NETWORK_H
#define	NETWORK_H

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<netdb.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>

#include	"init.h"
#include	"struct.h"
#include	"error.h"
#include	"init.h"
#include	"struct.h"
#include	"do_client.h"

#define	fldoff(name, field) \
	((int)&(((struct name *)0)->field))

/* Size of the field in the structure. */
#define	fldsiz(name, field) \
	(sizeof(((struct name *)0)->field))

/* Address of the structure from a field. */
#define	strbase(name, addr, field) \
	((struct name *)((char *)(addr) - fldoff(name, field)))

class Network {
private:
    int port_;
    char *ip_;
    t_client *client_;

public:
    Network(int port, char *ip, t_client *client);
    Network(const Network& orig);
    virtual ~Network();

    void initClient();
};

#endif	/* NETWORK_H */

