/*
** ftl.h for ftl.h in /home/marvyne/repertoire_rendu/my_FTL
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:18:19 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 12:02:49 2016 TOKPAHOLOU Marvyne
*/

#ifndef _FTL_H_
#define _FTL_H_
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct s_color			t_color;
typedef struct s_ship			t_ship;
typedef struct s_weapon			t_weapon;
typedef struct s_ftl_drive		t_ftl_drive;
typedef struct s_navigation_tools	t_navigation_tools;
typedef struct s_freight		t_freight;
typedef struct s_container		t_container;
typedef struct s_repair_command		t_repair_command;
typedef struct s_ennemis		t_ennemis;
typedef struct s_actuel_ennemis		t_actuel_ennemis;

void	my_putstr(char *str);
void	my_putstr_color(char *color, char *str);
char	*my_strdup(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_put_nbr(int nb);
int	my_strcmp(char *s1, char *s2);
char	*readline();
t_ship	*create_ship();
int	add_weapon_to_ship(t_ship *arg);
int	add_ftl_drive_to_ship(t_ship *arg);
int	add_navigation_tools_to_ship(t_ship *arg);
int	add_container_to_ship(t_ship *arg);
void	add_freight_to_container(t_ship *arg, t_freight *arg2);
void	del_freight_from_container(t_ship *arg, t_freight *element);
int	get_bonus(t_ship *arg);
void	ftl_drive_system_check(t_ship *arg);
void	navigation_tools_system_check(t_ship *arg);
void	weapon_system_check(t_ship *arg);
int	system_control(t_ship *arg);
int	ftl_drive_system_repair(t_ship *arg);
int	navigation_tools_system_repair(t_ship *arg);
int	weapon_system_repair(t_ship *arg);
int	system_repair(t_ship *arg);
void	coup_game(t_ship *arg);
int	jump(t_ship *arg);
int	attack(t_ship *arg);
int	detect(t_ship *arg);
void	add_ennemis(t_ship *arg);
void	aff_ennemis(t_ennemis *ens);
int	my_random(int percent);
int	stat(t_ship *arg);
int	help(t_ship *arg);
int	help_repair(t_ship *arg);
void	ajout_elem(t_ship *arg, t_weapon *w, t_ftl_drive * d, t_container *c);
void	aff_error_drive();
void	aff_fail_system(char *system);
void	manag_energy(t_ship *arg, int nb_energy_lost);
void	manag_attack_enm(t_ship *arg);
void	aff_system_endom(t_ship *arg, int nb_andom);
int	create_bonus(t_ship *arg);
void	check_create_bonus(t_ship *arg);
char	*genere_bonus();
void	loop_game(t_ship *arg);
int	check_readline(t_ship *arg, char *str);
int	check_cmd(t_ship *arg);

typedef struct			s_color
{
  char				*color;
  char				*unicode;
}				t_color;

typedef struct			s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_ftl_drive		*drive;
  struct s_navigation_tools	*navigation;
  struct s_container		*container;
}				t_ship;

typedef struct			s_weapon
{
  char				*system_state;
  int				damage;
}				t_weapon;

typedef struct			s_ftl_drive
{
  char				*system_state;
  int				energy;
}				t_ftl_drive;

typedef struct			s_navigation_tools
{
  char				*system_state;
  int				sector;
  int				evade;
  int				detect;
  struct s_actuel_ennemis	*ennemis;
}				t_navigation_tools;

typedef struct			s_freight
{
  char				*item;
  struct s_freight		*next;
  struct s_freight		*prev;
}				t_freight;

typedef struct			s_container
{
  struct s_freight		*first;
  struct s_freight		*last;
  int				nb_elem;
}				t_container;

typedef struct			s_repair_command
{
  char				*str;
  int				(*fonc)(t_ship* arg);
}				t_repair_command;

typedef struct			s_actuel_ennemis
{
  struct s_ennemis		*ennemis;
  int				present;
  int				nb_elem;
}				t_actuel_ennemis;

typedef struct			s_ennemis
{
  int				damage;
  int				life;
}				t_ennemis;

#endif
