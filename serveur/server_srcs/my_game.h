/*
** my_game.h for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jun 24 11:35:29 2013 laurent loukopoulos
** Last update Mon Jun 24 14:48:42 2013 laurent loukopoulos
*/

#ifndef		__MY_GAME_H__
#define		__MY_GAME_H__

#include	<stdbool.h>

typedef	struct	s_game
{
  int		*tab;
  int		tab_limit;
  int		fd_out;
  char		*save;
  char		*buff;

  bool		begin_g;
}		t_game;

void		my_enroll_client(t_game *);
void		my_send_graph(t_game *);

#endif
