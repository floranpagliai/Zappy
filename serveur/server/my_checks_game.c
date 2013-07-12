/*
** my_checks_game.c for zappy in /home/loukop_l//zappy-2016-paglia_f
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jul  1 13:23:42 2013 laurent loukopoulos
** Last update Tue Jul  2 16:43:49 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"

void		my_checkx(t_game *game, char **s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i])
    {
      if (strcmp("-x", s[i]) == 0)
	{
	  check_nb(s[i + 1]);
	  game->x = strdup(s[i + 1]);
	  j++;
	}
      i++;
    }
  if (j != 1)
    {
      printf("wrong length <-x int>\n");
      exit(0);
    }
  my_checky(game, s);
}

void		my_checky(t_game *game, char **s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i])
    {
      if (strcmp("-y", s[i]) == 0)
	{
	  check_nb(s[i + 1]);
	  game->y = strdup(s[i + 1]);
	  j++;
	}
      i++;
    }
  if (j != 1)
    {
      printf("wrong length <-y int>\n");
      exit(0);
    }
  my_checkt(game, s);
}

void		my_checkt(t_game *game, char **s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i])
    {
      if (strcmp("-t", s[i]) == 0)
	{
	  check_nb(s[i + 1]);
	  game->time = strdup(s[i + 1]);
	  j++;
	}
      i++;
    }
  if (j != 1)
    {
      printf("wrong time <-t int>\n");
      exit(0);
    }
  my_checkc(game, s);
}

void		my_checkc(t_game *game, char **s)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (s[i])
    {
      if (strcmp("-c", s[i]) == 0)
	{
	  check_nb(s[i + 1]);
	  game->c = atoi(s[i + 1]);
	  j++;
	}
      i++;
    }
  if (j != 1)
    {
      printf("wrong number of player by team <-c int>\n");
      exit(0);
    }
  my_checkn(game, s);
  my_create_perso(game);
}
