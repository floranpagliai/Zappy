/*
** my_irc.h for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:01:39 2013 laurent loukopoulos
** Last update Mon Jul  1 18:14:51 2013 laurent loukopoulos
*/

#ifndef		__MY_IRC_H__
# define	__MY_IRC_H__

# include	"struct.h"
# include	"my_game.h"

# define	NB_LISTEN	42

void		init_server(t_server*, char const *);
void		server_loop(t_server*, t_game*);
void            destroy_server(t_server *);

#endif
