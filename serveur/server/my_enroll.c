/*
** my_enroll.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jun 24 11:41:20 2013 laurent loukopoulos
** Last update Wed Jul 10 20:22:34 2013 laurent loukopoulos
*/

#include	"struct.h"
#include	"my_game.h"
#include	<stdbool.h>

void		my_enroll_client(t_game *game)
{
  int		s;

  if (strcmp(game->save, "GRAPHIC\n") == 0)
    {
      game->tab_limit++;
      game->tab[game->tab_limit - 1] = game->fd_out;
      my_send_graph(game);
      send_tab_rfc(game);
    }
  else if (my_check_client_name(game) == 1)
    my_perso_send(game);
  else
    {
      s = command_valid(game);
      if (s != -1) 
	dprintf(game->fd_out, "good command\n");
      else if (s == -1 && (strcmp(game->save, "GRAPHIC\n") != 0))
	dprintf(game->fd_out, "wrong command\n");
    }
}

void		my_send_graph(t_game *game)
{
  dprintf(game->fd_out, "msz %s %s\n", game->x, game->y);
  dprintf(game->fd_out, "sgt %s\n", game->time);

  my_team_send(game);
}

void		my_perso_set(t_game *game, int id)
{
  if (game->setx >= atoi(game->x))
    {
      game->setx = 0;
      game->sety++;
    }
  game->perso[id][0] = game->setx;
  game->perso[id][1] = game->sety;
  game->setx++;
}

void		my_perso_send(t_game *game)
{
  int		i;

  i = 0;
  if (my_check_nb_perso(game) != -1)
    {
      game->perso_n[game->id] = strdup(game->save);
      game->perso = malloc(sizeof(int *) * (game->nb_team * game->c));
      game->perso[game->id] = malloc(sizeof(int) * 2);
      my_perso_set(game, game->id);
      while (game->tab[i])
	{
	  dprintf(game->tab[i], "pnw #%d %d %d %d %d %s\n",
		  game->id, game->perso[game->id][0], game->perso[game->id][1],
		  3, 1, game->name[0]);
	  i++;
	}
      dprintf(game->fd_out, "%d\n%d %d\n", game->id, game->setx, game->sety);
      game->id++;
    }
}

void		my_team_send(t_game *game)
{
  int		i;

  i = 0;
  while (game->name[i])
    {
      dprintf(game->fd_out, "tna %s\n", game->name[i]);
      i++;
    }
}
