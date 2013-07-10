/*
** my_clock.c for zappy in /home/loukop_l//zappy-2016-paglia_f
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Tue Jul  2 15:46:52 2013 laurent loukopoulos
** Last update Tue Jul  2 23:13:50 2013 laurent loukopoulos
*/

#include	"struct.h"
#include	"my_game.h"

void		my_clock(t_game *game)
{
  if (game->begin_c == false)
    {
      game->t_init = clock();
      game->begin_c = true;
    }
}
