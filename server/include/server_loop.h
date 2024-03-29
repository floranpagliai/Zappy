/*
** server_loop.h for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:44:23 2013 laurent loukopoulos
** Last update Tue Jul  2 15:46:35 2013 laurent loukopoulos
*/

#ifndef		__SERVER_LOOP_H__
# define	__SERVER_LOOP_H__

# include	"struct.h"
# include	"my_game.h"

void		do_server(t_server *, t_game *);
void		do_client(t_server *, t_game *);
void		my_strrelay(t_client *, t_client *);
void            my_send_all(t_client *, t_client *);

#endif
