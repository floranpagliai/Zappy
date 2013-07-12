/*
** del_graph.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Thu Jul 11 14:51:19 2013 laurent loukopoulos
** Last update Thu Jul 11 14:56:33 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my_game.h"

void		del_fd_graph(t_game *game, int fd)
{
  int		i;

  i = 0;
  while (game->tab[i] != fd)
    i++;
  game->tab[i] = -10;
}
