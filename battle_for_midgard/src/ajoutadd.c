/*
** ajoutadd.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 23:38:29 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 23:38:51 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int                     ajout_rival(t_game *game)
{
  t_creature            *crea;

  crea = getCreature();
  game->rival = crea;
  my_putstr_color("red", "Un nouveau monstre est apparue\n");
  aff_rival(game);
  return (0);
}

void                    add_crea(t_game *game)
{
  if (game->friend->first == NULL)
    {
      game->friend->first = game->rival;
      game->friend->last = game->rival;
      game->friend->first->prev = NULL;
      game->friend->first->next = NULL;
    }
  else
    {
      game->rival->next = NULL;
      game->rival->prev = game->friend->last;
      game->friend->last->next = game->rival;
      game->friend->last = game->rival;
      game->friend->nb_elem++;
    }
}
