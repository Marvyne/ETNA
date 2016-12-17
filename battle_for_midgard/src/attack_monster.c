/*
** attack_monster.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 13:14:30 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 22:39:57 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"
#include <stdio.h>

int			slash_e(t_game *game)
{
  if (game->bag->combattant->pv > 0)
    {
      my_putstr_color("yellow", game->bag->combattant->name);
      my_putstr_color("blue", " Perd : 30 PDV\n Perd : 7 PM\n");
      if (game->rival->pm > 0)
	{
	  game->bag->combattant->pv -= 30;
	  game->bag->combattant->pm -= 7;
	  stat_friend(game);
	}
      else
	my_putstr_color("red", "L'enemi n'a plus de pm\n");
    }
  else if (game->bag->combattant->pv <= 0)
    {
      my_putstr_color("red", "Votre krakramon est K.O\n");
      my_putstr_color("red", "GAME OVER\n");
      game->character->etat_quit = 0;
      quit(game);
    }
  return (0);
}

int			fire_e(t_game *game)
{
  if (game->bag->combattant->pv > 0)
    {
      my_putstr_color("yellow", game->bag->combattant->name);
      my_putstr_color("blue", " Perd : 15 PDV\n Perd : 3 PM\n");
      game->bag->combattant->pv -= 15;
      game->bag->combattant->pm -= 3;
      stat_friend(game);
    }
  else if (game->bag->combattant->pv < 0)
    {
      game->friend->vivant = 0;
      my_putstr_color("red", "Votre krakramon est K.O\n");
      my_putstr_color("red", "GAME OVER\n");
      game->character->etat_quit = 0;
      quit(game);
    }
  else
    my_putstr_color("red", "L'enemi n'a plus de pm\n");
  return (0);
}

int			rest_e(t_game *game)
{
  my_putstr_color("yellow", game->rival->name);
  my_putstr_color("blue", " gagne : 10 PM\n");
  if (game->rival->pv > 0)
    {
      game->bag->combattant->pv -= 15;
      game->bag->combattant->pm -= 3;
    }
  else if (game->bag->combattant->pv < 0)
    {
      game->friend->vivant = 0;
      my_putstr_color("red", "Votre krakramon est K.O\n");
      my_putstr_color("red", "GAME OVER\n");
      game->character->etat_quit = 0;
      quit(game);
    }
  else
    my_putstr_color("red", "L'enemi n'a plus de pm\n");
  return (0);
}

int			gamble_e(t_game *game)
{
  if (game->rival->pv > 0)
    {
      rnd_attaque(game);
      stat_friend(game);
    }
  else if (game->bag->combattant->pv < 0)
    {
      game->friend->vivant = 0;
      my_putstr_color("red", "Votre krakramon est K.O\n");
      my_putstr_color("red", "GAME OVER\n");
      game->character->etat_quit = 0;
      quit(game);
    }
  else
    my_putstr_color("red", "L'enemi n'a plus de pm\n");
  return (0);
}

int			attack_monster(t_game *game)
{
  int			rnd;

  rnd = rand() % 4;
  if (rnd == 1)
    {
      my_putstr_color("red", "Le krakramon utilise : FIRE\n");
      fire_e(game);
    }
  if (rnd == 2)
    {
      my_putstr_color("red", "Le krakramon utilise : GAMBLE\n");
      gamble_e(game);
    }
  if (rnd == 3)
    {
      my_putstr_color("red", "Le krakramon utilise : REST\n");
      rest_e(game);
    }
  if (rnd == 4)
    {
      my_putstr_color("red", "Le krakramon utilise : SLASH\n");
      slash_e(game);
    }
  return (0);
}
