/*
** xfunc.h for zappy in /home/loukop_l//my_ircfinal/common_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Sun May 26 01:05:54 2013 laurent loukopoulos
** Last update Sun May 26 01:05:55 2013 laurent loukopoulos
*/

#ifndef		__XFUNC_H__
# define	__XFUNC_H__

# include	<netdb.h>
# include	<sys/time.h>

/* xfunc_file.c */
ssize_t		xwrite(int, const void *, size_t);
ssize_t		xread(int, void *, size_t);
void		xclose(int);

#endif
