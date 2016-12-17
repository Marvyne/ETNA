h/*
** ennemis.c for ennemis.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 12:12:07 2016 TOKPAHOLOU Marvyne
** Last update Tue Dec  6 22:45:13 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

void			add_ennemis(t_ship *arg)
{
  t_ennemis		*enm;
  int			life;
  int			damage;

  damage = 10 * ((0.5 * arg->navigation->ennemis->nb_elem) + 1);
  life = 20 * ((0.5 * arg->navigation->ennemis->nb_elem) + 1);
  enm = malloc(sizeof(*enm));
  if (enm != 0)
    {
      my_putstr_color("red", "[SYSTEM DETECT] : nouvel ennemi détecté, ");
      my_putstr_color("red", "il nous attaque !\n");
      enm->damage = damage;
      enm->life = life;
      arg->navigation->ennemis->ennemis = enm;
      arg->navigation->ennemis->nb_elem++;
      arg->navigation->ennemis->present = 1;
      aff_ennemis(enm);
    }
}

void	aff_ennemis(t_ennemis *enm)
{
  my_putstr_color("blue", "[ENNEMY DEBUG] : \n");
  my_putstr_color("magenta", "      ||     life : ");
  my_put_nbr(enm->life);
  my_putchar('\n');
  my_putstr_color("magenta", "      ||     damage : ");
  my_put_nbr(enm->damage);
  my_putchar('\n');
}

void	manag_attack_enm(t_ship *arg)
{
  int	system_endom;

  if (arg->navigation->ennemis->present == 1)
    {
      if (my_random(arg->navigation->evade) == 0)
	my_putstr_color("blue", "l'attaque ennemi nous a manquée\n");
      else
	{
	  arg->hull = (arg->hull - arg->navigation->ennemis->ennemis->damage);
	  my_putstr_color("magenta", "nous avons été touché\n");
	  if (my_random(20) == 0)
	    {
	      system_endom = my_random(3);
	      aff_system_endom(arg, system_endom);
	    }
	}
    }
}

void	aff_system_endom(t_ship *arg, int nb_random)
{
  if (nb_random == 0)
    {
      my_putstr_color("red", "[CRITICAL HIT] : système d'armement touché\n");
      free(arg->weapon->system_state);
      arg->weapon->system_state = my_strdup("off");
    }
  else if(nb_random == 1)
    {
      my_putstr_color("red", "[CRITICAL HIT] : système ftl drive touché\n");
      free(arg->drive->system_state);
      arg->drive->system_state = my_strdup("off");
    }
  else
     {
      my_putstr_color("red", "[CRITICAL HIT] : système navigation touché\n");
      free(arg->navigation->system_state);
      arg->navigation->system_state = my_strdup("off");
    }
}

int	check_readline(t_ship *arg, char *str)
{
  int	result;

  result = 1;
  if (my_strlen(str) == 0)
    {
      my_putstr_color("red", "[SYSTEM FAILURE] : lecteur de commande H.S\n");
      arg->navigation->ennemis->present = 10;
      result = 0;
    }
  return (result);
}
