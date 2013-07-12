/*
** command.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jul  8 11:37:21 2013 laurent loukopoulos
** Last update Fri Jul 12 15:39:15 2013 laurent loukopoulos
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

  game->command[0] = strdup("avance\n");
  game->command[1] = strdup("droite\n");
  game->command[2] = strdup("gauche\n");
  game->command[3] = strdup("voir\n");
  game->command[4] = strdup("inventaire\n");
  game->command[5] = strdup("prend\n");
  game->command[6] = strdup("pose\n");
  game->command[7] = strdup("expulse\n");
  game->command[8] = strdup("broadcast\n");
  game->command[9] = strdup("incantation\n");
  game->command[10] = strdup("mort dun joueur\n");
  game->command[11] = strdup("fin de jeu\n");
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
