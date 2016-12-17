/*
** my_cmd7.c for  in /home/kirito/etna/bfm/copie/Final
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Fri Dec  9 03:57:50 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 05:12:22 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int		buy_master_box(t_game *game)
{
  if (game->bag->rupes < 1000)
    my_putstr_color("red", "Vous n'avez plus assez de rupes, dommage\n");
  else if (game->character->etat == 0)
    {
      if (game->bag->rupes > 999)
	{
	  run_sdl2();
	  game->bag->rupes = game->bag->rupes - 1000;
	  game->bag->champ = game->bag->magic_master + 1;
	  my_putstr_color("green", "Vous venez d'acheter une master-box\n");
	}
    }
  else
    my_putstr_color("red", "Impossible d'acheter en combat !\n");
  return (0);
}

int                     use_sup_champ(t_game *game)
{
  int                   rnd;

  rnd = rand_rup(26, 50);
  if (game->bag->champ >= 1 && game->character->etat == 0 &&
      game->character->etat_quit == 0)
    {
      if (game->bag->combattant != NULL)
	{
	  game->bag->combattant->pv += rnd;
	  if (game->bag->combattant->pv < 100)
	    {
	      run_sdl4();
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
  else
    my_putstr_color("red", "Vous ne possedez pas de champignon !\n");
  return (0);
}
