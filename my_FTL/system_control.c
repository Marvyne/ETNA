/*
** system_control.c for system_control.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:12:04 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 11:53:38 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *arg)
{
  my_putstr_color("yellow", "verification du reacteur en cours ...\n");
  if ((my_strcmp(arg->drive->system_state, "online") == 0))
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "[SYSTEME FAILURE] : reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *arg)
{
  my_putstr_color("yellow","verification du système de navigation en ");
  my_putstr_color("yellow", "cours ...\n");
  if ((my_strcmp(arg->navigation->system_state, "online") == 0))
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : systeme de navigation ");
      my_putstr_color("red", "hors service!\n");
    }
}

void	weapon_system_check(t_ship *arg)
{
  my_putstr_color("yellow", "verification du systeme ");
  my_putstr_color("yellow", "d'armement en cours ...\n");
  if ((my_strcmp(arg->weapon->system_state, "online") == 0))
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : systeme d'armement ");
      my_putstr_color("red", "hors service!\n");
    }
}

int	system_control(t_ship *arg)
{
  ftl_drive_system_check(arg);
  navigation_tools_system_check(arg);
  weapon_system_check(arg);
  return (0);
}
