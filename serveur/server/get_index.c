/*
** get_index.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  9 20:00:28 2013 laurent loukopoulos
** Last update Wed Jul 10 20:16:48 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

void		str_in_tab(t_game *game)
{
  strcpy(game->board[game->index_tab], game->str);
  strcpy(game->board_rfc[game->index_tab], game->str2);
}

void		init_res(t_game *game)
{
  int		min;

  min = game->max/4;
  game->nb_pop = (min + (rand () % (game->max-min+1)));

  game->nb_deraumere_tot = 0;
  game->nb_linemate_tot = 0;
  game->nb_sibur_tot = 0;
  game->nb_mendiane_tot = 0;
  game->nb_phyras_tot = 0;
  game->nb_thystame_tot = 0;
  game->nb_food_tot = 0;
}

void		pop_res(t_game *game)
{
  pop_deraumere(game);
  pop_linemate(game);
  pop_sibur(game);
  pop_mendiane(game);
  pop_phyras(game);
  pop_thystame(game);
  pop_food(game);
  final_str(game);
}

void		init_tab(t_game *game)
{
  int		i;

  game->index_tab = 0;
  game->board = malloc(game->max * sizeof(char *));
  game->board_rfc = malloc(game->max * sizeof(char *));
  for(i = 0; i < game->max; i++)
    {
      game->board[i] = malloc(SIZE_STR * sizeof(char));
      game->board_rfc[i] = malloc(SIZE_STR * sizeof(char));
    }
  init_res(game);
  while (game->index_tab != game->max)
    {
      game->str[0] = '\0';
      game->str2[0] = '\0';
      pop_res(game);
      str_in_tab(game);
      game->index_tab++;
    }
}

void		get_index(t_game *game)
{
  int		cpt;
  int		x;
  int		y;

  cpt = 0;
  game->max = (game->gx * game->gy);
  game->pos_obj = malloc(game->gy * sizeof(*game->pos_obj));
  for (y = 0; y < game->gy; y++)
    {
      game->pos_obj[y] = malloc(game->gx * sizeof(int));
      memset(game->pos_obj[y], -1, game->gx);
    }
  y = 0;
  while (y < game->gy)
    {
      x = 0;
      while (x < game->gx)
	{
	  game->pos_obj[y][x] = cpt;
	  cpt++;
	  x++;
	}
      y++;
    }
  game->max = cpt;
}
