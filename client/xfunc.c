/*
** xfunc_file.c for zappy in /home/loukop_l//my_ircfinal/common_srcs
**
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
**
** Started on  Sun May 26 01:06:10 2013 laurent loukopoulos
** Last update Tue Jun 18 17:20:13 2013 laurent loukopoulos
*/

#include	<unistd.h>
#include	"../include/xfunc.h"
#include	"../include/error.h"
#include	<string.h>

ssize_t		xwrite(int fd, const void *buf, size_t count)
{
  ssize_t	nb_write;

  if ((nb_write = write(fd, buf, count)) == -1)
    error(ERROR_WRITE);
  return (nb_write);
}

ssize_t		xread(int fd, void *buf, size_t count)
{
  ssize_t	nb_read;

  if ((nb_read = read(fd, buf, count)) == -1)
    error(ERROR_READ);
  return (nb_read);
}

void		xclose(int fd)
{
  if (close(fd) == -1)
    error(ERROR_CLOSE);
}
