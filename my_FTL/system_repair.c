/*
** system_repair.c for system_repair.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:53:21 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 12:42:20 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

static const t_repair_command	command[] =
  {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {"help", help_repair},
    {NULL, NULL}
  };

int	ftl_drive_system_repair(t_ship *arg)
{
  my_putstr_color("yellow", "reparation du reacteur en cours ...\n");
  free(arg->drive->system_state);
  arg->drive->system_state = my_strdup("online");
  if (arg->drive->system_state == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : les reparations du ");
      my_putstr_color("red", "reacteur ont echoué\n");
      return (1);
    }
  else
    {
      my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
      return (0);
    }
}

int	navigation_tools_system_repair(t_ship *arg)
{
  my_putstr_color("yellow", "reparation du systeme de navigation en ");
  my_putstr_color("yellow", "cours ...\n");
  free(arg->navigation->system_state);
  arg->navigation->system_state = my_strdup("online");
  if (arg->navigation->system_state == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : les reparations du système ");
      my_putstr_color("red", "de navigation ont echoué\n");
      return (1);
    }
  else
    {
      my_putstr_color("green", "reparation termine! systeme de ");
      my_putstr_color("green", "navigation OK!\n");
      return (0);
    }
}

int	weapon_system_repair(t_ship *arg)
{
  my_putstr_color("yellow", "reparation du systeme d'armement en cours ...\n");
  free(arg->weapon->system_state);
  arg->weapon->system_state = my_strdup("online");
  if (arg->weapon->system_state == NULL)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : les reparations du système ");
      my_putstr_color("red","armement ont echoué\n");
      return (1);
    }
  else
    {
      my_putstr_color("green","reparation termine! systeme d'armement OK!\n");
      return (0);
    }
}

int	system_repair(t_ship *arg)
{
  char	*answer;
  int	i;
  int	trouve;

  i = 0;
  trouve = 0;
  my_putstr_color("magenta", "\nRepair_system~> ");
  answer = readline();
  if (check_readline(arg, answer) == 1)
    {
      while (command[i].str != NULL)
	{
	  if ((my_strcmp(command[i].str, answer) == 0))
	    {
	      command[i].fonc(arg);
	      trouve = 1;
	      return (0);
	    }
	  i++;
	}
      if ((trouve != 1))
	my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
    }
  return (1);
}

int	help_repair(t_ship *arg)
{
  int	i;

  arg->hull = arg->hull - 1;
  arg->hull = arg->hull + 1;
  i = 0;
  my_putstr_color("yellow", "Commande system disponible : \n");
  while (command[i].str != NULL)
    {
      my_putstr(command[i].str);
      my_putchar('\n');
      i++;
    }
  return (0);
}
