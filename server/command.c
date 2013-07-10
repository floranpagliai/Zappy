/*
** command.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jul  8 11:37:21 2013 laurent loukopoulos
** Last update Tue Jul  9 08:50:22 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s2[i])
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (0);
}

void		my_command(t_game *game)
{
  game->command = malloc(sizeof(char *) * 13);

  game->command[0] = strdup("Avance\n");
  game->command[1] = strdup("Droite\n");
  game->command[2] = strdup("Gauche\n");
  game->command[3] = strdup("Voir\n");
  game->command[4] = strdup("Inventaire\n");
  game->command[5] = strdup("Prend\n");
  game->command[6] = strdup("Pose\n");
  game->command[7] = strdup("Expulse\n");
  game->command[8] = strdup("Broadcast\n");
  game->command[9] = strdup("Incantation\n");
  game->command[10] = strdup("Mort dun joueur\n");
  game->command[11] = strdup("Fin de jeu\n");
}

int		command_valid(t_game *game)
{
  int		i;

  i = 0;
  while (game->command[i])
    {
      if (my_strcmp(game->save, game->command[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}
