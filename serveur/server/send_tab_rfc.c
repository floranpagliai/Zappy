/*
** send_tab_rfc.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Wed Jul 10 17:39:09 2013 laurent loukopoulos
** Last update Wed Jul 10 20:22:05 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

void		send_tab_rfc(t_game *game)
{
  int		cpt;
  int		i;

  (void)game;
  (void)cpt;
  cpt = 0;
  i = 0;
  while (game->tab[i])
    {
      while (cpt != game->max)
	{
	  dprintf(game->tab[i], "%s\n", game->board_rfc[cpt]);
	  cpt++;
	}
      i++;
    }
}
