/*
-1;2802;0c** monster.c for  in /home/kirito/etna/bfm/tokpah_m/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Tue Dec  6 09:28:15 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 00:12:54 2016 YOUSSEF seif-eddine
*/

#include <unistd.h>
#include "../include/my.h"

int                     Vitality(int pv)
{
  int                   i;
  int                   count;

  count = 10;
  i = 0;
  while (i != (pv/10) && pv > 0)
    {
      my_putstr("\033[34;7m");
      my_putchar(' ');
      my_putchar(' ');
      my_putstr("\033[0m");
      i++;
    }
  while (count > pv && pv > 0)
    {
      my_putstr("  ");
      count--;
    }
  return (0);
}

int                     Vitality_a(int pv)
{
  int                   i;
  int                   count;

  count = 10;
  i = 0;
  while (i != (pv/10) && pv > 0)
    {
      my_putstr("\033[31;7m");
      my_putchar(' ');
      my_putchar(' ');
      my_putstr("\033[0m");
      i++;
    }
  while (count > pv && pv > 0)
    {
      my_putstr("  ");
      count--;
    }
  return (0);
}

int			first_init_monster(t_game *game)
{
  t_creature		*crea;

  crea = getCreature();
  add_crea(game);
  my_putstr("\033[31;7m");
  my_putstr_color("red", " ----------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "|");
  my_putstr_color("red", crea->name);
  my_putstr_color("red", " | PV :  ");
  my_putstr("\033[0m");
  Vitality(crea->pv);
  my_putstr("\033[31;7m");
  my_putstr_color("red", "  \n---------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "\nPv :");
  my_put_nbr(crea->pv);
  my_putstr_color("red", " / ");
  my_put_nbr(crea->pvmax);
  my_putstr_color("red", "\nPm : ");
  my_put_nbr(crea->pm);
  my_putstr_color("red", " / ");
  my_put_nbr(crea->pmmax);
  my_putchar('\n');
  return (0);
}

int                     stat_friend(t_game *game)
{
  my_putstr("\033[34;7m");
  my_putstr(" ----------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "|");
  my_putstr_color("red", game->bag->combattant->name);
  my_putstr_color("red", " | PV :  ");
  my_putstr("\033[34;7m");
  Vitality_a(game->bag->combattant->pv);
  my_putstr("\033[34;7m");
  my_putstr(" \n----------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "\nPv :");
  my_put_nbr(game->bag->combattant->pv);
  my_putstr_color("red", " / ");
  my_put_nbr(game->bag->combattant->pvmax);
  my_putstr_color("red", "\nPm : ");
  my_put_nbr(game->bag->combattant->pm);
  my_putstr_color("red", " / ");
  my_put_nbr(game->bag->combattant->pmmax);
  my_putchar('\n');
  return (0);
}

int                     aff_rival(t_game *game)
{
  my_putstr("\033[31;7m");
  my_putstr_color("red", " ----------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "|");
  my_putstr_color("red", game->rival->name);
  my_putstr_color("red", " | PV :  ");
  my_putstr("\033[0m");
  Vitality(game->rival->pv);
  my_putstr("\033[31;7m");
  my_putstr("\n");
  my_putstr_color("red", "  ---------------------------------\n");
  my_putstr("\033[0m");
  my_putstr_color("red", "\nPv :");
  my_put_nbr(game->rival->pv);
  my_putstr_color("red", " / ");
  my_put_nbr(game->rival->pvmax);
  my_putstr_color("red", "\nPm : ");
  my_put_nbr(game->rival->pm);
  my_putstr_color("red", " / ");
  my_put_nbr(game->rival->pmmax);
  my_putchar('\n');
  return (0);
}
