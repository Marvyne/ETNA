/*
** my_cmd6.c for  in /home/kirito/etna/bfm/copie/Final
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Fri Dec  9 03:08:24 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 05:15:07 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int		stat(t_game *game)
{
  if (game->bag->combattant != NULL)
    {
      my_putstr_color("green", "Stat combattant : \n");
      my_putstr_color("green", "prénom : ");
      my_putstr(game->bag->combattant->name);
      my_putstr("\n");
      my_putstr_color("green", "Pv : ");
      if (game->bag->combattant->pv > 100)
	game->bag->combattant->pv = 100;
      my_put_nbr(game->bag->combattant->pv);
      my_putstr("\n");
      my_putstr_color("green", "Pm : ");
      my_put_nbr(game->bag->combattant->pm);
      my_putstr("\n");
    }
  return (0);
}

int		inventaire_ch(t_game *game)
{
  if (game->bag->champ > 0)
    {
      my_putstr_color("yellow", "Champignon : ");
      my_put_nbr(game->bag->champ);
      my_putstr("\n");
    }
  if (game->bag->magic_box > 0)
    {
      my_putstr_color("yellow", "Master box : ");
      my_put_nbr(game->bag->magic_box);
      my_putstr("\n");
    }
  if (game->bag->rupes > 0)
    {
      my_putstr_color("yellow", "Rupes : ");
      my_put_nbr(game->bag->rupes);
      my_putstr("\n");
    }
  if (game->bag->super_champ > 0)
    {
      my_putstr_color("yellow", "Super champignon : ");
      my_put_nbr(game->bag->rupes);
      my_putstr("\n");
    }
  return (0);
}

int		magasin(t_game *game)
{
  my_putstr_color("green", "Disponibilité du magasin : \n");
  my_putstr_color("green", "Magic box prix : 90 rupes\n");
  my_putstr_color("green", "Vous en possedez : ");
  my_put_nbr(game->bag->magic_box);
  my_putstr("\n");
  my_putstr_color("green", "Super-Magic box prix : 200 rupes\n");
  my_putstr_color("green", "Vous en possedez : ");
  my_put_nbr(game->bag->magic_sup);
  my_putstr("\n");
  my_putstr_color("green", "Master-Magic box prix : 1000 rupes\n");
  my_putstr_color("green", "Vous en possedez : ");
  my_put_nbr(game->bag->magic_master);
  my_putstr("\n");
  my_putstr_color("green", "Champi prix : 30 rupes\n");
  my_putstr_color("green", "Vous en possedez : ");
  my_put_nbr(game->bag->champ);
  my_putstr("\n");
  my_putstr_color("green", "Super-champi prix : 100 rupes\n");
  my_putstr_color("green", "Vous en possedez : ");
  my_put_nbr(game->bag->super_champ);
  my_putstr("\n");
  return (0);
}

int		buy_sup_box(t_game *game)
{
  if (game->bag->rupes < 200)
    my_putstr_color("red", "Vous n'avez plus assez de rupes, dommage\n");
  else if (game->character->etat == 0)
    {
      if (game->bag->rupes > 199)
        {
	  run_sdl1();
          game->bag->rupes = game->bag->rupes - 200;
          game->bag->champ = game->bag->magic_sup + 1;
          my_putstr_color("green", "Vous venez d'acheter une super-box\n");
        }
    }
  else
    my_putstr_color("red", "Impossible d'acheter en combat !\n");
  return (0);
}

int		buy_sup_champ(t_game *game)
{
if (game->bag->rupes < 100)
    my_putstr_color("red", "Vous n'avez plus assez de rupes, dommage\n");
  else if (game->character->etat == 0)
    {
      if (game->bag->rupes > 99)
        {
	  run_sdl4();
          game->bag->rupes = game->bag->rupes - 100;
          game->bag->champ = game->bag->super_champ + 1;
          my_putstr_color("green", "Vous venez d'acheter un super-champi\n");
        }
    }
  else
    my_putstr_color("red", "Impossible d'acheter en combat !\n");
  return (0);
}
