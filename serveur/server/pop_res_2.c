/*
** pop_res_2.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Wed Jul 10 10:52:52 2013 laurent loukopoulos
** Last update Wed Jul 10 10:54:11 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

void		pop_mendiane(t_game *game)
{
  int		ran;

  game->nb_mendiane = 00;
  if (game->nb_mendiane_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_mendiane_tot) == 2)
	{
	  game->nb_mendiane++;
	  game->nb_mendiane_tot++;
	}
      else if (check_ok(game, game->nb_mendiane_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_mendiane++;
	      game->nb_mendiane_tot++;
	    }
	}
    }
}

void		pop_phyras(t_game *game)
{	
  int		ran;

  game->nb_phyras = 00;
  if (game->nb_phyras_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_phyras_tot) == 2)
	{
	  game->nb_phyras++;
	  game->nb_phyras_tot++;
	}
      else if (check_ok(game, game->nb_phyras_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_phyras++;
	      game->nb_phyras_tot++;
	    }
	}
    }
}

void		pop_thystame(t_game *game)
{
  int		ran;

  game->nb_thystame = 00;
  if (game->nb_thystame_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_thystame_tot) == 2)
	{
	  game->nb_thystame++;
	  game->nb_thystame_tot++;
	}
      else if (check_ok(game, game->nb_thystame_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_thystame++;
	      game->nb_thystame_tot++;
	    }
	}
    }
}

void		pop_food(t_game *game)
{
  int		ran;

  game->nb_food = 0;
  if (game->nb_food_tot != game->nb_pop)
    {
      if (check_ok(game, game->nb_food_tot) == 2)
	{
	  game->nb_food++;
	  game->nb_food_tot++;
	}
      else if (check_ok(game, game->nb_food_tot) == 1)
	{
	  ran = (rand() % 2);
	  if (ran == 1)
	    {
	      game->nb_food++;
	      game->nb_food_tot++;
	    }
	}
    }
}
