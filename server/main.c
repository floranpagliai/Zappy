/*
** main.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:41:57 2013 laurent loukopoulos
** Last update Wed Jul 10 17:42:04 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"
#include	<time.h>

int		main(int ac, char **av)
{
  t_server	server;
  t_game	game;

  srand(time(0));
  game.setx = 0;
  game.sety = 0;
  game.id = 0;
  game.begin_c = false;
  game.tab = malloc(sizeof(int));
  my_param(&game, av);
  game.tab_limit = 0;
  (void)game;
  (void)ac;

  my_command(&game);
  game.perso_n = malloc(sizeof(char *) * (game.nb_team * game.c));
  game.gx = atoi(game.x);
  game.gy = atoi(game.y);
  get_index(&game);
  init_tab(&game);
  init_server(&server, game.port);
  server_loop(&server, &game);
  destroy_server(&server);

  return (0);
}

void		my_param(t_game *game, char **s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i])
    {
      if (s[i][0] == '-')
	j++;
      i++;
    }
  if (j != 6)
    {
      printf("wrong arguments try again\n");
      exit(0);
    }
  else
    my_checkp(game, s);
}

void		check_nb(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] >= '0' && s[i] <= '9')
	i++;
      else
	{
	  printf("pls enter a real number\n");
	  exit(0);
	}
    }
}
