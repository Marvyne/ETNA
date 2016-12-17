/*
** my_command3.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 08:57:48 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 00:13:29 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int				let_s_fight(t_game *game)
{
  if (game->character->etat == 0)
    {
      ajout_rival(game);
      game->character->etat_quit = 1;
      my_putstr_color("blue", "Vous passez dans l'état : IB\n");
      team(game);
      prompt_choice(game);
      game->character->etat = 1;
      my_putstr("\n");
      game->character->bool_m = 0;
    }
  else if (game->character->etat == 1)
    my_putstr_color("red", "Vous êtes déjà en combat\n");
  return (0);
}

int				slash(t_game *game)
{
  if ((game->character->etat == 1))
    {
      if (game->rival->pv > 0)
  	{
	  reduc_cmd2(game, 1);
	  attack_monster(game);
	  if (game->rival->pv >= 0)
	    aff_rival(game);
	  else if (game->rival->pv <= 0)
	    reduc_cmd2(game, 2);
  	}
    }
  else if (game->character->etat == 0)
    reduc_cmd2(game, 3);
  return (0);
}

int				fire(t_game *game)
{
  if (game->character->etat == 1)
    {
      if (game->rival->pv > 0)
  	{
	  reduc_cmd22(game, 1);
	  attack_monster(game);
	  if (game->rival->pv >= 0)
	    aff_rival(game);
	  else if (game->rival->pv <= 0)
	    {
	      reduc_cmd22(game, 2);
	      game->character->etat_quit = 0;
	      rnd_sup(game);
	      rnd_master(game);
	    }
  	}
    }
  else if (game->character->etat == 0)
    reduc_cmd22(game, 3);
  return (0);
}

int				gamble(t_game *game)
{
  if ((game->character->etat == 1))
    {
      if (game->rival->pv > 0)
  	{
	  reduc_cmd222(game, 1);
	  if (game->rival->pv > 0)
	    aff_rival(game);
	  else if (game->rival->pv <= 0)
	    {
	      reduc_cmd222(game, 2);
	      rnd_sup(game);
	      rnd_master(game);
	    }
  	}
    }
  else if (game->character->etat == 0)
    reduc_cmd222(game, 3);
  return (0);
}

int				rest(t_game *game)
{
  if ((game->character->etat == 1) && game->character->etat_quit == 1)
    {
      attack_monster(game);
      if (game->bag->combattant->pv > 0)
    	{
    	  my_putstr_color("blue", "lance l'attaque : REST\n");
    	  game->bag->combattant->pm += 10;
	  aff_rival(game);
	  rnd_sup(game);
	  rnd_master(game);
    	}
    }
  else if (game->character->etat == 0)
    {
      my_putstr_color("red", "Vous ne pouvez utilisez vos krakramon hors ");
      my_putstr_color("red", "des combats\n");
    }
  return (0);
}
