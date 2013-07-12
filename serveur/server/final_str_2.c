/*
** final_str_2.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Wed Jul 10 10:50:08 2013 laurent loukopoulos
** Last update Wed Jul 10 10:51:54 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

void		check_nb_mendiane(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->nb_mendiane);
  strcat(game->str2, buf);
  if (game->nb_mendiane != 0)
    strcat(game->str, " mendiane");
}

void		check_nb_phyras(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->nb_phyras);
  strcat(game->str2, buf);
  if (game->nb_phyras != 0)
    strcat(game->str, " phyras");
}

void		check_nb_thystame(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d", game->nb_thystame);
  strcat(game->str2, buf);
  if (game->nb_thystame != 0)
    strcat(game->str, " thystame");
}

void		check_nb_food(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, " %d ", game->nb_food);
  strcat(game->str2, buf);
  if (game->nb_food != 0)
    strcat(game->str, " food");
}

void		final_str(t_game *game)
{
  get_num_map(game);
  init_str2(game);
  check_nb_food(game);
  check_nb_deraumere(game);
  check_nb_linemate(game);
  check_nb_sibur(game);
  check_nb_mendiane(game);
  check_nb_phyras(game);
  check_nb_thystame(game);
}
