/*
** my_game.h for zappy in /home/loukop_l//zappy-2016-paglia_f/server_srcs
** 
** Made by laurent loukopoulos
** Login   <loukop_l@epitech.net>
** 
** Started on  Mon Jun 24 11:35:29 2013 laurent loukopoulos
** Last update Wed Jul 10 20:24:13 2013 laurent loukopoulos
*/

#ifndef		__MY_GAME_H__
#define		__MY_GAME_H__

#include	<stdbool.h>
#include	<time.h>
#include	<stdio.h>
#include        <sys/types.h>
#include        <sys/ipc.h>
#include        <sys/shm.h>

#define		SIZE_STR 74

typedef	struct	s_game
{
  int		*tab;
  int		tab_limit;
  int		fd_out;
  char		*save;
  char		*buff;

  char		**command;

  clock_t	t_init;
  clock_t	t_final;

  float		myclock;

  char		*port;
  char		*x;
  char		*y;
  char		*time;
  int		c;
  int		nb_team;
  char		**name;

  int		id;
  int		**perso;
  char		**perso_n;

  bool		begin_g;
  bool		begin_c;
  int		setx;
  int		sety;

  /* INDEX */

  int		**pos_obj;

  /* INVENTaIRE MAP */

  int		nb_deraumere_tot;
  int		nb_linemate_tot;
  int		nb_sibur_tot;
  int		nb_mendiane_tot;
  int		nb_phyras_tot;
  int		nb_thystame_tot;
  int		nb_food_tot;

  int		nb_deraumere;
  int		nb_linemate;
  int		nb_sibur;
  int		nb_mendiane;
  int		nb_phyras;
  int		nb_thystame;
  int		nb_food;

  /* TAB DE STR */

  char 		**board;
  char 		**board_rfc;

  /* STR FINAL */
  char		str[SIZE_STR];
  char		str2[SIZE_STR];

  /* VAR TAB */
  int		index_tab;
  int		get_x;
  int		get_y;
  int		gx;
  int		gy;
  int		nb_pop;
  int		max;
}		t_game;

void		init_str2(t_game *);
int		get_num_map(t_game *);
void		check_nb_deraumere(t_game *);
void		check_nb_linemate(t_game *);
void		check_nb_sibur(t_game *);
void		check_nb_mendinate(t_game *);
void		check_nb_phyras(t_game *);
void		check_nb_thystame(t_game *);
void		check_nb_food(t_game *);
void		final_str(t_game *);
int		check_ok(t_game *, int);
void		pop_deraumere(t_game *);
void		pop_linemate(t_game *);
void		pop_sibur(t_game *);
void		pop_mendiane(t_game *);
void		pop_phyras(t_game *);
void		pop_thystame(t_game *);
void		pop_food(t_game *);
void		str_in_tab(t_game *);
void		init_res(t_game *);
void		pop_res(t_game *);
void		init_tab(t_game *);
void		get_index(t_game *);
void		send_tab_rfc(t_game *);

void		my_enroll_client(t_game *);
void		my_send_graph(t_game *);
void		my_param(t_game *, char **);
void		my_checkp(t_game *, char **);
void		my_checkx(t_game *, char **);
void		my_checky(t_game *, char **);
void		check_nb(char *);
void		my_checkt(t_game *, char **);
void		my_checkc(t_game *, char **);
void		my_checkn(t_game *, char **);
void		my_create_perso(t_game *);
int		my_check_client_name(t_game *);
void		my_command(t_game *);

void		my_clock(t_game *);

void		my_check_tab(t_game *, int, int, char **);
void		exist_check(char *, char **);

void		my_team_send(t_game *);
void		my_perso_set(t_game *, int);
void		my_perso_send(t_game *);
int		my_check_nb_perso(t_game *);

int		command_valid(t_game *);

#endif
