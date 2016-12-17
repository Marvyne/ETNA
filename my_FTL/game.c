/*
** game.c for game.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 09:49:48 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 12:03:19 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

static const t_repair_command	command[] =
  {
    {"attack",attack},
    {"detect",detect},
    {"jump", jump},
    {"getbonus", get_bonus},
    {"controlsystem", system_control},
    {"repairsystem", system_repair},
    {"stat", stat},
    {"help", help},
    {NULL, NULL}
  };

void	coup_game(t_ship *arg)
{
  char	*answer;
  char	*trouve;
  int	i;

  i = 0;
  trouve = "False";
  my_putstr_color("cyan", "\nWhat is your order captain~>");
  answer = readline();
  if (check_readline(arg, answer) == 1)
    {
      while (command[i].str != NULL)
	{
	  if ((my_strcmp(command[i].str, answer) == 0))
	    {
	      manag_attack_enm(arg);
	      command[i].fonc(arg);
	      trouve = "True";
	    }
	  i++;
	}
      if (my_strcmp(trouve, "False") == 0)
	my_putstr_color("red", "[SYSTEM FAILURE] : commmande invalide\n");
    }
}

int	jump(t_ship *arg)
{
  if (my_strcmp(arg->drive->system_state, "online") == 0)
    {
      if (arg->navigation->ennemis->present == 0)
	{
	  int	ennemi;

	  my_putstr_color("yellow","Chargement de la puissance du saut PRL\n");
	  arg->navigation->sector = arg->navigation->sector + 1;
	  arg->drive->energy = arg->drive->energy - 1;
	  arg->navigation->detect = 0;
	  my_putstr_color("green", "JUMP !\n");
	  ennemi = my_random(30);
	  if (ennemi != 0)
	    add_ennemis(arg);
	}
      else if (arg->navigation->ennemis->present != 0)
	aff_error_drive();
    }
  else
    aff_fail_system("navigation");
  return (0);
}

int	attack(t_ship *arg)
{
  int	nb_energy_lost;

  nb_energy_lost = 0;
  if (arg->navigation->ennemis->present == 0)
    my_putstr_color("red", "[SYSTEM FAILURE] : pas d'ennemis à proximité\n");
  else
    {
      if (my_strcmp(arg->weapon->system_state, "online") == 0)
	{
	  arg->navigation->ennemis->ennemis->life =			\
	    arg->navigation->ennemis->ennemis->life - arg->weapon->damage;
	  aff_ennemis(arg->navigation->ennemis->ennemis);
	  nb_energy_lost = nb_energy_lost + my_random(50);
	}
      else
	aff_fail_system("weapon");
    }
  if ((arg->navigation->ennemis->present) &&
      (arg->navigation->ennemis->ennemis->life <= 0))
    {
      arg->navigation->ennemis->present = 0;
      my_putstr_color("green", "Nous avons abattu l'ennemi !\n");
      manag_energy(arg, nb_energy_lost);
    }
  return (0);
}

int		detect(t_ship *arg)
{
  t_freight	*frei;

  frei = malloc(sizeof(*frei));
  if (frei == 0)
    return (0);
  check_create_bonus(arg);
  if (arg->navigation->detect == 0)
    {
      my_putstr_color("yellow","[DETECTION SYSTEM] : cargaison de fret detecté");
      my_putstr_color("yellow","\nAjout des cargaisons de fret en cours ...\n");
      arg->navigation->detect = 1;
      create_bonus(arg);
      frei = arg->container->first;
      my_putstr_color("green", "Cargaisons de fret Ajoutées\n");
    }
  else if (arg->navigation->detect == 1)
    my_putstr_color("red", "[NAVIGATION SYSTEM] : detection déja effectuée \n");
  return (0);
}

int	help(t_ship *arg)
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
