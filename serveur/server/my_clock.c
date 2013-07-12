/*
** my_clock.c for zappy in /home/loukop_l//zappy-2016-paglia_f
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  2 15:46:52 2013 laurent loukopoulos
** Last update Fri Jul 12 18:51:47 2013 laurent loukopoulos
*/

#include	"struct.h"
#include	"my_game.h"

void		my_clock(t_game *game)
{
  int		i;
  int		j;

  (void)j;
  my_alloc_tab(game);
  if (game->begin_c == false)
    {
      game->t_init = clock();
      game->begin_c = true;
    }
  j = clock();
  while (game->times[i])
    i++;
  game->times[i] = ((float) j);
}

void		my_alloc_tab(t_game *game)
{
  game->times = malloc(sizeof(float) * (game->nb_team * game->c));
  game->id_times = malloc(sizeof(int) * (game->nb_team * game->c));
}
