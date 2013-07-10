/*
** my_check_names.c for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jul  1 16:36:05 2013 laurent loukopoulos
** Last update Wed Jul 10 15:16:03 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my_game.h"

void		my_checkn(t_game *game, char **av)
{
  int		i;
  int		s;
  int		pos;

  i = 1;
  s = 0;
  pos = 0;
  while (av[i])
    {
      if (strcmp("-n", av[i]) == 0)
	{
	  pos = i + 1;
	  while (av[i + 1] && av[i + 1][0] != '-')
	    {
	      i++;
	      s++;
	    }
	}
      i++;
    }
  game->nb_team = s;
  my_check_tab(game, pos, s, av);
}

void		my_check_tab(t_game *game, int pos, int s, char **av)
{
  int		i;
  char		**tab;

  tab = malloc (sizeof(char *) * s + 1);

  i = 0;
  while (av[pos] && av[pos][0] != '-')
    {
      exist_check(av[pos], tab);
      tab[i] = strdup(av[pos]);
      pos++;
      i++;
    }
  game->name = tab;
}

void		exist_check(char *s, char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (strcmp(s, tab[i]) == 0)
	{
	  printf("in -n name called twice or more\n");
	  exit(0);
	}
      i++;
    }
}

int		my_check_client_name(t_game *game)
{
  int		i;
  char		*str;

  str = strdup(game->save);
  str[strlen(str) - 1] = '\0';
  i = 0;
  while (game->name[i])
    {
      if (strcmp(game->name[i], str) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		my_check_nb_perso(t_game *game)
{
  int		i;
  int		t;

  i = 0;
  t = 0;
  while(game->perso_n[i])
    {
      if (strcmp(game->save, game->perso_n[i]) == 0)
	t++;
      i++;
    }
  if (t >= game->c)
    return (-1);
  return (0);
}
