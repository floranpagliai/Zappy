/*
** main.c for zappy in /home/loukop_l//my_ircfinal/client_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:08:10 2013 laurent loukopoulos
** Last update Sun May 26 01:08:11 2013 laurent loukopoulos
*/

#include	<stdlib.h>
#include	"init.h"
#include	"struct.h"
#include	"do_client.h"

int		main(int ac, char **av)
{
  t_client	client;

  if (ac == 3)
    {
      client_init(atoi(av[2]), av[1], &client);
      do_client(&client);
      client_close(&client);
    }
  else
    {
      fprintf(stderr, "Usage: %s port\n", av[0]);
    }
  return (EXIT_SUCCESS);
}
