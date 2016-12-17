/*
** air_shed.c for air_shed.c in /home/marvyne/repertoire_rendu/my_FTL
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:42:28 2016 TOKPAHOLOU Marvyne
** Last update Fri Nov 11 17:29:25 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

t_ship			*create_ship()
{
  t_ship		*hull;
  t_weapon		*weapon;
  t_ftl_drive		*drive;
  t_navigation_tools	*navigation;
  t_container		*container;

  hull = NULL;
  weapon = NULL;
  drive = NULL;
  navigation = NULL;
  container = NULL;
  my_putstr_color("yellow", "construction du vaisseau en cours...\n");
  if ((hull = malloc(sizeof(*hull))) == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu être construit ");
      my_putstr_color("red", "par manque de matériaux\n");
      return (NULL);
    }
  else
    {
      hull->hull = 50;
      hull->navigation = navigation;
      ajout_elem(hull, weapon, drive, container);
    }
  return (hull);
}

void	ajout_elem(t_ship *arg, t_weapon *w, t_ftl_drive *d, t_container *c)
{
  arg->weapon = w;
  arg->drive = d;
  arg->container = c;
  my_putstr_color("green", "amélioration du vaisseau termine!\n");
}

int		add_weapon_to_ship(t_ship *arg)
{
  t_weapon	*weapon;

  weapon = NULL;
  my_putstr_color("yellow", "ajout des armes en cours...\n");
  weapon = malloc(sizeof(*weapon));
  if (weapon == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez ");
      my_putstr_color("red", "tenté d'ajouter les armes\n");
      return (0);
    }
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  arg->weapon = weapon;
  my_putstr_color("green", "les armes on été ajoutés avec succès!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *arg)
{
  t_ftl_drive	*drive;

  drive = NULL;
  my_putstr_color("yellow", "ajout des réacteur en cours...\n");
  drive = malloc(sizeof(*drive));
  if (drive == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez ");
      my_putstr_color("red", "posé le reacteur\n");
      return (0);
    }
  drive->energy = 10;
  drive->system_state = my_strdup("online");
  arg->drive = drive;
  my_putstr_color("green", "le réacteur a été ajouté avec succès!\n");
  return (1);
}

int			add_navigation_tools_to_ship(t_ship *arg)
{
  t_navigation_tools	*navigation;
  t_actuel_ennemis	*ennemis;

  ennemis = NULL;
  navigation = NULL;
  my_putstr_color("yellow", "ajout des outils de navigations...\n");
  if ((navigation = malloc(sizeof(*navigation))) == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez ");
      my_putstr_color("red", "posé les outils de navigations\n");
      return (0);
    }
  if ((ennemis = malloc(sizeof(*ennemis))) == NULL)
    return (0);
  ennemis->ennemis = NULL;
  ennemis->nb_elem = 0;
  ennemis->present = 0;
  navigation->sector = 0;
  navigation->evade = 25;
  navigation->detect = 0;
  navigation->system_state = my_strdup("online");
  navigation->ennemis = ennemis;
  arg->navigation = navigation;
  my_putstr_color("green", "outils de navigations ajoutés avec succès!\n");
  return (1);
}
