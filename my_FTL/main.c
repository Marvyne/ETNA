/*
** my_ftl.c for my_ftl.c in /home/marvyne/repertoire_rendu/my_FTL
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:37:36 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 10:59:49 2016 TOKPAHOLOU Marvyne
*/

#include	"ftl.h"

int		main()
{
  t_ship	*ship;
  int		a;
  int		b;
  int		c;
  int		d;

  srand(time(NULL));
  ship = create_ship();
  a = add_weapon_to_ship(ship);
  b = add_ftl_drive_to_ship(ship);
  c = add_navigation_tools_to_ship(ship);
  d = add_container_to_ship(ship);
  if (a == 1 && b == 1 && c == 1 && d == 1)
    loop_game(ship);
  else
    {
      my_putstr_color("red","[ERROR CRITIQUE]: lancement du vaisseau impossib");
      my_putstr_color("red", "le pour cause d'explosion\n");
    }
  free(ship);
  return (0);
}

void	loop_game(t_ship *arg)
{
  int	win;
  int	i;

  i = 0;
  win = 0;
  while (arg->navigation->sector < 10 && win == 0 && check_cmd(arg) == 0)
    {
      coup_game(arg);
      i++;
      if ((arg->hull <= 0) || (arg->drive->energy <= 0))
	win = 1;
    }
  if (win == 1)
    {
      if (arg->hull <= 0)
	my_putstr_color("red", "\n\n\nVous n'avez plus de vie\n");
      else if (arg->drive->energy <= 0)
	my_putstr_color("red", "\n\n\nVous n'avez plus d'énergie\n");
      stat(arg);
      my_putstr_color("red", "\n                  ||||  GAME OVER  ||||\n");
    }
  else if (arg->navigation->ennemis->present != 10  && win != 1)
      my_putstr_color("green", "                     ||||  YOU WIN  ||||\n");
}

int	check_cmd(t_ship *arg)
{
  if (arg->navigation->ennemis->present == 10)
    {
      my_putstr_color("red", "Interruption de la partie\n");
      return (1);
    }
  return (0);
}
