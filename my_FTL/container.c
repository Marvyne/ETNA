/*
** container.c for container.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 15:11:48 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 10:27:32 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

int		add_container_to_ship(t_ship *arg)
{
  t_container	*container;

  my_putstr_color("yellow", "ajout du container en cours...\n");
  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explosé quand vous avez ");
      my_putstr_color("red", "posé le container\n");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  arg->container = container;
  my_putstr_color("green", "le container a été ajouté avec succès!\n");
  return (1);
}

void		add_freight_to_container(t_ship *arg, t_freight *arg2)
{
  if (arg->container->first == NULL)
    {
      arg->container->first = arg2;
      arg->container->last = arg2;
      arg->container->first->next = NULL;
      arg->container->first->prev = NULL;
    }
  else
    {
      arg2->next = NULL;
      arg2->prev = arg->container->last;
      arg->container->last->next = arg2;
      arg->container->last = arg2;
    }
  arg->container->nb_elem = arg->container->nb_elem + 1;
}

void		del_freight_from_container(t_ship *arg, t_freight *element)
{
  if (element == arg->container->first || element == arg->container->last)
    {
      if (element == arg->container->first)
	{
	  arg->container->first = NULL;
	  arg->container->last = NULL;
	}
      else
	{
	  arg->container->last = element->prev;
	  arg->container->last->next = NULL;
	}
    }
  else
    {
      element->prev->next = element->next;
      element->next->prev = element->prev;
    }
  free(element);
  arg->container->nb_elem = arg->container->nb_elem - 1;
}

int		get_bonus(t_ship *arg)
{
  t_freight	*tmp;

  tmp = arg->container->first;
  while (tmp != NULL)
    {
      if ((my_strcmp(tmp->item, "attackbonus") == 0))
	arg->weapon->damage = arg->weapon->damage + 5;
      else if ((my_strcmp(tmp->item, "evadebonus") == 0))
	arg->navigation->evade = arg->navigation->evade +3;
      else if ((my_strcmp(tmp->item, "energy") == 0))
	arg->drive->energy = arg->drive->energy + 1;
      tmp = tmp->next;
    }
  tmp = arg->container->last;
  while (tmp != NULL)
    {
      del_freight_from_container(arg, tmp);
      tmp = tmp->prev;
    }
  my_putstr_color("yellow","Recuperation des matériaux utiles en cours ...\n");
  my_putstr_color("green", "Matériaux utiles recuperes\n");
  return (0);
}
