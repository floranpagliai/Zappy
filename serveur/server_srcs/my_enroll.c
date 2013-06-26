/*
** my_enroll.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jun 24 11:41:20 2013 laurent loukopoulos
** Last update Mon Jun 24 14:57:19 2013 laurent loukopoulos
*/

#include	"struct.h"
#include	"my_game.h"

void		my_enroll_client(t_game *game)
{
  if (strcmp(game->save, "GRAPHIC\n") == 0)
    {
      game->tab_limit++;
      game->tab = malloc (sizeof(int) * game->tab_limit);
      game->tab[game->tab_limit - 1] = game->fd_out;
      my_send_graph(game);
    }
  else
    write(game->fd_out, "En cours de dev\n", strlen("En cours de dev\n"));

  /*  printf("\nbegin\n%send\n", game->buff);
      write(game->fd_out, "bonjour client\n", strlen("bonjour client\n"));
      printf("\n save(%d) : %s\n", game->fd_out, game->save);*/
}

void		my_send_graph(t_game *game)
{
  write(game->fd_out, "BIENVENUE\n", strlen("BIENVENUE\n"));
}
