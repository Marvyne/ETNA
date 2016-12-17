/*
** magic_catch.c for  in /home/kirito/etna/bfm/tokpah_m/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Tue Dec  6 09:43:24 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 22:51:27 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

#include <stdio.h>

int			init_catch(t_game *game)
{
  int			rnd;

  if (game->bag->magic_box > 0 && game->character->etat == 1)
    {
      msg_first(game, 1);
      rnd = rand() % 3;
      if (rnd == 1 && game->character->bool_m == 0)
	{
	  msg_first(game, 2);
	  add_crea(game);
	  game->character->bool_m +=1;
	  game->character->etat_quit = 0;
	  game->character->etat = 0;
	}
      else if (game->character->bool_m == 0)
	msg_first(game, 3);
      else
	my_putstr_color("blue", "Utilisation raté\n");
    }
  else
    my_putstr_color("red", "Vous ne posseder pas de magic_box !\n");
  return (0);
}

int			init_catch_sup(t_game *game)
{
  int			rnd;

  if (game->bag->magic_sup > 0 && game->character->etat == 1)
    {
      my_putstr_color("yellow", game->character->name);
      my_putstr_color("yellow", " utilise une super magic box !\n");
      rnd = rand() % 2;
      if (rnd == 1)
	{
	  my_putstr_color("green", "Et hop !\n");
	  my_putstr_color("green", " attrapé !\n");
	}
      else
	{
	  my_putstr_color("red", "La capture à échoué !\n");
	  my_putstr_color("red", "Le krakra-Monster vous pousse violament\n");
	  my_putstr_color("red", "\nUn nouvel enemie est apparue : \n");
	  first_init_monster(game);
	}
    }
  else
    my_putstr_color("red", "Vous ne posseder pas de super-magic box !\n");
  return (0);
}

int			init_catch_master(t_game *game)
{
  if (game->bag->magic_master > 0 && game->character->etat == 1)
    {
      my_putstr_color("yellow", game->character->name);
      my_putstr_color("yellow", " utilise une master magic box !\n");
      my_putstr_color("green", "Et hop !\n");
      my_putstr_color("green", " attrapé !\n");
    }
  else
    my_putstr_color("red", "Vous ne posseder pas de master-magic box !\n");
  return (0);
}

int			rnd_sup(t_game *game)
{
  int			rnd;

  rnd = rand() % 3;
  if (rnd == 1)
    {
      my_putstr_color("green", "Vous avez dropper une ");
      my_putstr_color("green", "Super-magic box\n");
      game->bag->magic_sup += 1;
    }
  return (0);
}

int			rnd_master(t_game *game)
{
  int			rnd;

  rnd = rand() % 10;
  if (rnd == 1)
    {
      my_putstr_color("green", "Vous avez dropper une ");
      my_putstr_color("green", "Master-magic box\n");
      game->bag->magic_master += 1;
    }
  return (0);
}
