/*
** my_command4.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 15:19:53 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 00:03:49 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int			you_are(t_game *game)
{
  if (game->character->etat_quit == 0)
    prompt_choice(game);
  else
    my_putstr_color("red", "Vous n'êtes pas en combat !\n");
  return (0);
}

int			yoshi(t_game *game)
{
  t_creature		*crea;

  crea = game->friend->first;
  while (crea != NULL && game->friend->vivant == 1)
    {
      if (my_strcmp(crea->name, "Yoshi") == 0)
	{
	  game->bag->combattant = crea;
	  if (game->bag->combattant->pv > 0)
	    {
	      my_putstr_color("blue", "Vous avez invoquez : ");
	      my_putstr_color("yellow", "Yoshi");
	    }
	  else if (game->bag->combattant->pv < 0)
	    my_putstr_color("red", "Vous ne pouvez invoque un krakramon K.O");
	}
      else
	my_putstr_color("red", "Vous ne pouvez invoque un krakramon K.O");
      crea = crea->next;
    }
  return (0);
}

int			bob_bomb(t_game *game)
{
  t_creature		*crea;

  crea = game->friend->first;
  while (crea != NULL && game->friend->vivant == 1)
    {
      if (my_strcmp(crea->name, "Bob bomb") == 0)
	{
	  game->bag->combattant = crea;
	  if (game->bag->combattant->pv > 0)
	    {
	      my_putstr_color("blue", "Vous avez invoquez : ");
	      my_putstr_color("yellow", "Bob Bomb");
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

int			koopa(t_game *game)
{
  t_creature		*crea;

  crea = game->friend->first;
  while (crea != NULL && game->friend->vivant == 1)
    {
      if (my_strcmp(crea->name, "Koopa") == 0)
	{
	  game->bag->combattant = crea;
	  if (game->bag->combattant->pv > 0)
	    {
	      my_putstr_color("blue", "Vous avez invoquez : ");
	      my_putstr_color("yellow", "Koopa");
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

int			maskas(t_game *game)
{
  t_creature		*crea;

  crea = game->friend->first;
  while (crea != NULL && game->friend->vivant == 1)
    {
      if (my_strcmp(crea->name, "Maskas") == 0)
	{
	  game->bag->combattant = crea;
	  if (game->bag->combattant->pv > 0)
	    {
	      my_putstr_color("blue", "Vous avez invoquez : ");
	      my_putstr_color("yellow", "Maskas");
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
