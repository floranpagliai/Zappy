/*
** my_game.c for zappy in /home/loukop_l//zappy-2016-paglia_f
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Wed Jun 19 18:00:01 2013 laurent loukopoulos
** Last update Thu Jun 20 17:49:12 2013 laurent loukopoulos
*/

#include	"struct.h"

void		my_game(char *buf_in, int out)
{
  char		*res;

  write(out, "bonjour client graphique\n", strlen("bonjour client graphique\n"));
  res = my_str(buf_in);
  printf("%s\n", res);
}

char		*my_str(char *buf_in)
{
  int		length;
  int		i;
  char		*res;

  i = 0;
  length =  my_count_last_str(buf_in);
  res = malloc(sizeof(char) * (strlen(buf_in) - length) + 1);
  while(buf_in[length])
    {
      res[i] = buf_in[length];
      i++;
      length++;
    }
  res[i] = '\0';

  return (res);
}

int		my_count_last_str(char *res)
{
  int		i;

  i = strlen(res);
  i -= 2;
  while (res[i] != '\n')
    i--;
  i++;
  return (i);
}