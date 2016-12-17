/*
** gamble.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 09:40:31 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 14:46:34 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int			rnd_attaque(t_game *game)
{
  int			rnd;
  int			i;

  i = 0;
  rnd = rand() % 20;
  while (i != rnd)
    i++;
  if (i == rnd)
    {
      if (rnd == 0)
	my_putstr_color("red", "Pas de chance !");
      else if (rnd >= 1 && rnd <= 5)
	my_putstr_color("red", "Il tape 1 fois\n");
      else if (rnd >= 6 && rnd <= 10)
	my_putstr_color("red", "Il tape 2 fois !\n");
      else if (rnd >= 11 && rnd <= 15)
	my_putstr_color("red", "Il tape 3 fois !!\n");
      else if (rnd >= 16 && rnd <= 20)
	my_putstr_color("red", "Il tape 4 fois !!!\n Sa pique !\n");
      game->rival->pv -= i;
    }
  return (0);
}
