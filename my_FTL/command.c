/*
** command.c for command.c in /home/marvyne/repertoire_rendu/my_FTL/tokpah_m
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Wed Nov  9 17:30:17 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 09:40:09 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

int	stat(t_ship *arg)
{
  my_putstr_color("yellow", "space_ship statement : \n");
  my_putstr_color("magenta", "	||   hull : ");
  my_put_nbr(arg->hull);
  my_putchar('\n');
  my_putstr_color("magenta", "	||   damage : ");
  my_put_nbr(arg->weapon->damage);
  my_putchar('\n');
  my_putstr_color("magenta", "	||   energy : ");
  my_put_nbr(arg->drive->energy);
  my_putchar('\n');
  my_putstr_color("magenta", "	||   sector : ");
  my_put_nbr(arg->navigation->sector);
  my_putchar('\n');
  my_putstr_color("magenta", "	||   evade : ");
  my_put_nbr(arg->navigation->evade);
  my_putchar('\n');
  return (0);
}

int		create_bonus(t_ship *arg)
{
  int		i;
  t_freight	*t[10];
  int		bon_malloc;

  bon_malloc = 1;
  i = 0;
  while (i < 10)
    {
      t[i] = NULL;
      if ((t[i] = malloc(sizeof(*t[i]))) == NULL)
	bon_malloc = 0;
      else
      {
	  t[i]->item = my_strdup(genere_bonus());
	  add_freight_to_container(arg, t[i]);
      }
      i++;
    }
  return (bon_malloc);
}

void	check_create_bonus(t_ship *arg)
{
  if (create_bonus(arg) == 0)
    {
      my_putstr_color("red", "il y a eu un problème lors de la détection");
      my_putstr_color("red", " de la cargaison\n");
      arg->navigation->detect = 2;
    }
}
char	*genere_bonus()
{
  char	*result;
  int	nb_rand;

  nb_rand = my_random(33);
  if (my_random(70) == 0)
    result = "scrap";
  else
    {
      if (nb_rand == 0)
	result = "energy";
      else if (nb_rand == 1)
	result = "attackbonus";
      else if (nb_rand == 2)
	result = "evadebonus";
      else
	result = "scrap";
    }
  return (result);
}
