/*
** my_relay.c for zappy in /home/loukop_l//my_ircfinal/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:01:13 2013 laurent loukopoulos
** Last update Mon Jun 24 15:09:34 2013 laurent loukopoulos
*/

#include	<stdio.h>
#include	"my_irc.h"
#include	"struct.h"
#include	<string.h>

void            my_strrelay(t_client *c1, t_client *c2)
{
  int		save;
  char		name[10];
  int		i;
  int		nb;

  i = 0;
  nb = sprintf(name, "%d: ", c1->fd - 3);
  while (i < nb)
    {
      c2->buf_write[c2->write_end] = name[i++];
      c2->write_end = (c2->write_end + 1) % BUF_MAX;
    }
  save = c1->read_start;
  while ((c1->read_start != c1->read_end) &&
	 (((c2->write_end + 1) % BUF_MAX) != c2->write_start))
    {
      c2->buf_write[c2->write_end] = c1->buf_read[c1->read_start];
      c2->write_end = (c2->write_end + 1) % BUF_MAX;
      c1->read_start = (c1->read_start + 1) % BUF_MAX;
    }
  c1->read_start = save;
}

void		my_send_all(t_client * c, t_client *tr)
{
  while (c)
    {
      if (tr->fd != c->fd)
	my_strrelay(tr, c);
      c = c->next;
    }
  tr->read_start = tr->read_end;
}
