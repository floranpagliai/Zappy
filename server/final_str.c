/*
** final_str.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server/test
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  9 20:05:21 2013 laurent loukopoulos
** Last update Wed Jul 10 12:25:30 2013 laurent loukopoulos
*/

#include	<errno.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<time.h>
#include	"my_game.h"

void		init_str2(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->get_x);

  strcat(game->str2, "bct ");
  strcat(game->str2, buf);
  snprintf(buf, 10, "%d", game->get_y);
  strcat(game->str2, buf);
  return;
}

int		get_num_map(t_game *game)
{
  game->get_y = 0;
  while (game->get_y < game->gy)
    {
      game->get_x = 0;
      while (game->get_x != game->gx)
	{ 
	  if (game->index_tab == game->pos_obj[game->get_y][game->get_x])
	    return (0);
	  game->get_x++;
	}
      game->get_y++;
    }
  return(1);
}

void		check_nb_deraumere(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->nb_deraumere);
  strcat(game->str2, buf);
  if (game->nb_deraumere != 0)
    strcat(game->str, " deraumere");
}

void		check_nb_linemate(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->nb_linemate);
  strcat(game->str2, buf);
  if (game->nb_linemate != 0)
    strcat(game->str, " linemate");
}

void		check_nb_sibur(t_game *game)
{
  char		buf[10];

  snprintf(buf, 10, "%d ", game->nb_sibur);
  strcat(game->str2, buf);
  if (game->nb_sibur != 0)
    strcat(game->str, " sibur");
}
