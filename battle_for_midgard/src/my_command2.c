/*
** my_command2.c for  in /home/kirito/etna/bfm/tokpah_m/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Tue Dec  6 13:18:07 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 23:40:47 2016 YOUSSEF seif-eddine
*/
#include "../include/my.h"

int                                     magic_catch(t_game *game)
{
  init_catch(game);
  return (0);
}

int                                     magic_catch_sup(t_game *game)
{
  init_catch_sup(game);
  return (0);
}

int                                     magic_catch_master(t_game *game)
{
  init_catch_master(game);
  return (0);
}

int					etat(t_game *game)
{
  if (game->character->etat == 0)
    {
      game->character->etat_quit = 0;
      my_putstr_color("yellow", "Etat : OoB\n");
    }
  if (game->character->etat == 1)
    my_putstr_color("yellow", "Etat : IB\n");
  return (0);
}

int					team(t_game *game)
{
  t_creature				*crea;

  crea = game->friend->first;
  while (crea != NULL)
    {
      my_putstr_color("blue", crea->name);
      my_putstr("\n");
      crea = crea->next;
    }
  return (0);
}
