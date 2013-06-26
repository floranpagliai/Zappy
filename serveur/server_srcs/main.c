/*
** main.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 00:41:57 2013 laurent loukopoulos
** Last update Mon Jun 24 15:21:37 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	"my_game.h"

int		main(int ac, char **av)
{
  t_server	server;
  t_game	game;

  my_param(&game, av);
  game.tab_limit = 0;
  (void)game;
  if (ac == 2)
    {
      ++av;
      init_server(&server, *av);
      server_loop(&server);
      destroy_server(&server);
    }
  else
    printf("Usage: %s port\n", *av);
  return (0);
}

void		my_param(t_game *game, char **s)
{

}
