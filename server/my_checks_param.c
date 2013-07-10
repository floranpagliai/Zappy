/*
** my_checks_param.c for zappy in /home/loukop_l//zappy-2016-paglia_f
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jul  1 13:21:18 2013 laurent loukopoulos
** Last update Mon Jul  1 13:23:10 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"

void		my_checkp(t_game *game, char **s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i])
    {
      if (strcmp("-p", s[i]) == 0)
	{
	  check_nb(s[i + 1]);
	  game->port = malloc(sizeof(char) * strlen(s[i + 1]));
	  strcpy(game->port, s[i + 1]);
	  j++;
	}
      i++;
    }
  if (j != 1)
    {
      printf("wrong port <-p xxxx>\n");
      exit(0);
    }
  my_checkx(game, s);
}
