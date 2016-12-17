/*
** fonction.c for fonction.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:34:06 2016 TOKPAHOLOU Marvyne
** Last update Fri Nov 11 12:17:25 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_random(int percent)
{
  int	random;

  random = (rand()% 100);
  if (percent == 33)
    {
      if (random < 33)
	return (0);
      else if (random < 66)
	return (1);
      else if (random < 99)
	return (2);
      else
	return (3);
    }
  else if (percent != 3)
    {
      if (random >= percent)
	return (0);
      else
	return (1);
    }
  else
    return (rand()% 3);
}

void	aff_error_drive()
{
   my_putstr_color("red", "[SYSTEM FAILURE] : impossible de quitter ");
   my_putstr_color("red", "le secteur tant qu'un ennemi est présent\n");
}

void	aff_fail_system(char *system)
{
  my_putstr_color("red", "[SYSTEM FAILURE] : système");
  if (my_strcmp(system, "weapon") == 0)
    my_putstr_color("red", " d'armement endommagé, impossible d'attaquer\n");
  else if (my_strcmp(system, "navigation") == 0)
    my_putstr_color("red", " de détection endommagé, détection impossible\n");
  else
    my_putstr_color("red", " ftl drive endommagé, impossible de jumper");
}

void	manag_energy(t_ship *arg, int nb_energy_lost)
{
  arg->drive->energy = arg->drive->energy - nb_energy_lost;
  my_putstr_color("yellow", "Le combat nous aura couté ");
  my_put_nbr(nb_energy_lost);
  my_putstr_color("yellow", " cellules d'énergie\n");
}
