/*
** magic_msg.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 22:45:15 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 22:50:22 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int			msg_first(t_game *game, int msg)
{
  if (msg == 1)
    {
      game->bag->magic_box -= 1;
      my_putstr_color("yellow", game->character->name);
      my_putstr_color("yellow", " utilise une magic box !\n");
    }
  else if (msg == 2)
    {
      my_putstr_color("green", "Et hop !\n");
      my_putstr_color("red", game->rival->name);
      my_putstr_color("green", " attrapé !\n");
    }
  else if (msg == 3)
    {
      my_putstr_color("red", "La capture à échoué !\n");
      my_putstr_color("red", "Le krakra-Monster vous pousse violament\n");
      ajout_rival(game);
    }
  return (0);
}
