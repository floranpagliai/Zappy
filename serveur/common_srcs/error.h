/*
** error.h for zappy in /home/loukop_l//my_ircfinal/common_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:06:17 2013 laurent loukopoulos
** Last update Sun May 26 01:06:17 2013 laurent loukopoulos
*/

#ifndef		__ERROR_H__
# define	__ERROR_H__

# include	<stdio.h>
# include	<stdlib.h>
# include	"xfunc.h"

# define	ERROR_TEST		"error test"
# define	ERROR_WRITE		"write"
# define	ERROR_READ		"read"
# define	ERROR_CLOSE		"close"
# define	ERROR_GETRLIMIT		"getrlimit"
# define	ERROR_GETPROTOBYNAME	"getprotobyname"
# define	ERROR_SOCKET		"socket"
# define	ERROR_BIND		"bind"
# define	ERROR_LISTEN 		"listen"
# define	ERROR_SELECT 		"select"
# define	ERROR_CONNECT 		"connect"
# define	ERROR_ACCEPT 		"accept"
# define	ERROR_MALLOC 		"malloc"

# define        error(msg)                                     	\
  {                                                            	\
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);  	\
    abort();						       	\
  }

# define        error_and_close(msg, fd)		       	\
  {                                                            	\
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);  	\
    xclose(fd);						       	\
    abort();						       	\
  }

# define        error_and_destroy(msg, server)			\
  {								\
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);  	\
    destroy_server(server);				       	\
    abort();						       	\
  }

# define        error_close_and_destoy(msg, server, fd)		\
  {                                                            	\
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);  	\
    destroy_server(server);				       	\
    xclose(fd);						       	\
    abort();						       	\
  }

#endif
