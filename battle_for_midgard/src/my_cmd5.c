/*
** my_cmd5.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Fri Dec  9 00:02:40 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 05:11:22 2016 YOUSSEF seif-eddine
*/
#include "../include/my.h"

int                     kucco(t_game *game)
{
  t_creature            *crea;

  crea = game->friend->first;
  while (crea != NULL && game->friend->vivant == 1)
    {
      if (my_strcmp(crea->name, "Kucco") == 0)
	{
	  game->bag->combattant = crea;
	  if (game->bag->combattant->pv > 0)
	    {
	      my_putstr_color("blue", "Vous avez invoquez : ");
	      my_putstr_color("yellow", "Kucco");
	    }
	  else if (game->bag->combattant->pv < 0)
	    {
	      game->friend->vivant = 0;
	      my_putstr_color("red", "Votre krakamon est K.O\n");
	    }
	}
      else
	my_putstr_color("red", "Vous ne pouvez invoque un krakramon K.O");
      crea = crea->next;
    }
  return (0);
}

int			ach_champ(t_game *game)
{
  if (game->bag->rupes < 30)
    my_putstr_color("red", "Vous n'avez plus assez de rupes, dommage\n");
  else if (game->character->etat == 0)
    {
      if (game->bag->rupes > 30)
	{
	  run_sdl3();
	  game->bag->rupes = game->bag->rupes - 30;
	  game->bag->champ = game->bag->champ + 1;
	  my_putstr_color("green", "Vous venez d'acheter un champignon\n");
	}
    }
  else
    my_putstr_color("red", "Impossible d'acheter en combat !\n");
  return (0);
}

int			ach_magic_b(t_game *game)
{
  if (game->bag->rupes < 90 && game->character->etat == 0)
    my_putstr_color("red", "Vous n'avez plus assez de rupes, dommage\n");
  else
    {
      game->bag->rupes = game->bag->rupes - 90;
      game->bag->magic_box++;
      my_putstr_color("green", "Vous venez d'acheter une magic box\n");
    }
  return (0);
}

int			use_champ(t_game *game)
{
  int			rnd;

  rnd = rand_rup(15, 25);
  if (game->bag->champ >= 1 && game->character->etat == 0 &&
      game->character->etat_quit == 0)
    {
      if (game->bag->combattant != NULL)
	{
	  game->bag->combattant->pv += rnd;
	  if (game->bag->combattant->pv < 100)
	    {
	      game->bag->champ -= 1;
	      my_putstr_color("green", "Vous venez d'utiliser un champignon !\n");
	      my_putstr_color("green", "Votre combattant regagne ses PV !\n");
	      if (game->bag->combattant->pv > 100)
		game->bag->combattant->pv = 100;
	    }
	  else  if (game->bag->combattant->pv == 100)
	    my_putstr_color("red", "Inutile de gaspillez !\n");
	}
    }
  else if (game->bag->combattant == NULL)
    my_putstr_color("red", "Vous ne possedez pas de krakramon!\n");
  else
    my_putstr_color("red", "Vous ne possedez pas de champignon !\n");
  return (0);
}
