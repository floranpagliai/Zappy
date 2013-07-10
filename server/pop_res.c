/*
** pop_res.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  9 20:43:35 2013 laurent loukopoulos
** Last update Wed Jul 10 17:37:35 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

int		check_ok(t_game *game, int total)
{
  int		res;
  int		res_pop;

  if (total < game->nb_pop)
    {
      res = game->max - game->index_tab;
      res_pop = game->nb_pop - total;
      if (res_pop == res)
	return (2);
      return (1);
    }
  else
    return (0);
}

void		pop_deraumere(t_game *game)
{
  int		ran;

  game->nb_deraumere = 00;
  if (game->nb_deraumere_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_deraumere_tot) == 2)
	{
	  game->nb_deraumere++;
	  game->nb_deraumere_tot++;
	}
      else if (check_ok(game, game->nb_deraumere_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_deraumere++;
	      game->nb_deraumere_tot++;
	    }
	}
    }
}

void		pop_linemate(t_game *game)
{
  int		ran;

  game->nb_linemate = 00;
  if (game->nb_linemate_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_linemate_tot) == 2)
	{
	  game->nb_linemate++;
	  game->nb_linemate_tot++;
	}
      else if (check_ok(game, game->nb_linemate_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_linemate++;
	      game->nb_linemate_tot++;
	    }
	}
    }
}

void		pop_sibur(t_game *game)
{
  int		ran;

  game->nb_sibur = 0;
  if (game->nb_sibur_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_sibur_tot) == 2)
	{
	  game->nb_sibur++;
	  game->nb_sibur_tot++;
	}
      else if (check_ok(game, game->nb_sibur_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_sibur++;
	      game->nb_sibur_tot++;
	    }
	}
    }
}
