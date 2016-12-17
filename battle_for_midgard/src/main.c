/*
1;2802;0c1;2802;0c** main.c for  in /home/kirito/etna/bfm/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Mon Dec  5 10:16:17 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 05:14:29 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

static const t_pointer_s                     tab_choice[] =
  {
    {&yoshi, "Yoshi"},
    {&koopa, "Koopa"},
    {&bob_bomb, "Bob bomb"},
    {&maskas, "Maskas"},
    {&kucco, "Kucco"},
    {NULL, NULL}
  };

static const t_pointer                     tab[] =
  {
    {&help_me, "help me !!!"},
    {&magic_catch, "magic catch"},
    {&magic_catch_sup, "super-magic catch"},
    {&magic_catch_master, "master-magic catch"},
    {&quit, "quit"},
    {&inventaire, "inventaire"},
    {&krakra_help, "krakra_help"},
    {&etat, "etat"},
    {&team, "team"},
    {&you_are, "you are the chose one"},
    {&let_s_fight, "let's fight"},
    {&fire, "fire"},
    {&slash, "slash"},
    {&gamble, "gamble"},
    {&rest, "rest"},
    {&ach_champ, "buy champ"},
    {&ach_magic_b, "buy magic box"},
    {&use_champ, "use champ"},
    {&stat, "stat"},
    {&buy_sup_champ, "buy super-champ"},
    {&buy_sup_box, "buy super-magic box"},
    {&buy_master_box, "buy master-magic box"},
    {&use_sup_champ, "use super-champ"},
    {&magasin, "magasin"},
    {NULL, NULL}
  };

t_game					*create_game()
{
  t_game				*game;

  my_putstr_color("red", "Lancement du jeu en cour\n");
  if ((game = malloc(sizeof(t_game))) == NULL)
    {
      my_putstr_color("red", "La création du jeu à échoué\n");
      return (NULL);
    }
  game->rival = NULL;
  game->friend = NULL;
  game->character = NULL;
  game->bag = NULL;
  my_putstr_color("red", "Creation du jeu : OK !\n");
  return (game);
}

int                                     prompt_choice(t_game *game)
{
  int                                   i;
  char                                  *choice;

  i = 0;
  my_putstr_color("blue", "Choix krakramon > ");
  if ((choice = readline()) != NULL)
    {
      while (tab_choice[i].str != NULL)
	{
	  if (my_strcmp(tab_choice[i].str, choice) == 0)
	    {
	      if (tab_choice[i].pf2(game) == 0)
		return (0);
	      return (1);
	    }
	  i++;
	}
      my_putmsg_r("[SYSTEM FAILURE] : commande inconnue\n");
      free(choice);
      return (prompt_choice(game));
    }
  free(choice);
  return (1);
}

int                                     prompt(t_game *game)
{
  int                                   i;
  char                                  *choice;

  i = 0;
  my_putstr_color("yellow", "waiting_for_orders> ");
  if ((choice = readline()) != NULL)
    {
      while (tab[i].str != NULL)
	{
	  if (my_strcmp(tab[i].str, choice) == 0)
	    {
	      if (tab[i].pf(game) == 0)
		return (0);
	      return (1);
	    }
	  i++;
	}
      my_putmsg_r("[SYSTEM FAILURE] : commande inconnue\n");
      free(choice);
      return (prompt(game));
    }
  free(choice);
  return (1);
}

void    pars(int argc, char **argv, t_game *game)
{
  if ((argc == 3) && (my_strcmp(argv[1], "-n") == 0))
    init_character(game, argv[2]);
  else
    {
      if (argc > 1)
	{
	  my_putstr_color("red", "Krakra: C'est pas très valide tout ça\n");
	  my_putstr_color("red", "Je vais choisir le nom :p \n");
	}
      init_character(game, "KriKra");
    }
}

int			main(int argc, char **argv)
{
  t_game		*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (0);
  srand (time (NULL));
  game = create_game();
  explain();
  init_bag(game);
  pars(argc, argv, game);
  init_friend(&game);
  init_character(game, argv[2]);
  ajout_rival(game);
  while (game->character->bool == 0)
    prompt(game);
  free_me_too(game);
  return (0);
}
