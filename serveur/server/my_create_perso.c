/*
** my_create_perso.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  2 16:42:57 2013 laurent loukopoulos
** Last update Tue Jul  2 17:42:12 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"

void		my_create_perso(t_game *game)
{
  int		i;

  i = 0;
  game->perso = malloc(sizeof(int *) * atoi(game->y));
  while(i != atoi(game->y))
    {
      game->perso[i] = malloc(sizeof(int));
      i++;
    }
}
