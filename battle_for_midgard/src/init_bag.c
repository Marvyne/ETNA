/*
** init_bag.c for  in /home/kirito/etna/bfm/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Mon Dec  5 11:19:05 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 03:47:43 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int			explain()
{
  my_putstr_color("green", "Bienvenue dans N64 - Catch monster\n");
  my_putstr_color("green", "Je m'appel krakra, ");
  my_putstr_color("green", "je vais t'expliquer comment jouer !\n");
  my_putstr_color("green", "Il vous sera mis à disposition un sac.\n");
  my_putstr_color("green", "Celui contient : \n");
  my_putstr_color("green", "1 | 5 magic-box\n");
  my_putstr_color("green", "2 | 5 potion PDV/PM\n");
  my_putstr_color("green", "La magicbox te permet de capturer des monstres\n");
  my_putstr_color("green", "Les potions te permettrons de soigner t'es ");
  my_putstr_color("green", "krakra-monster.\nTu pourra avoir une chance de ");
  my_putstr_color("green", "dropper des magicbox et des potion apres chaque ");
  my_putstr_color("green", "combat.\n");
  my_putstr_color("green", "Si tu as besoin de moi tu n'aura qu'a m'appeler ");
  my_putstr_color("green", "avec la commande krakra_help\n");
  my_putstr_color("green", "Bonne chance à toi jeune aventurier !\n");
  return (0);
}

int			init_bag(t_game *game)
{
  t_bag			*bag;

  my_putstr_color("green", "\nAttend ! Ton sac est vide !\n");
  if ((bag = malloc(sizeof(t_bag))) == NULL)
    {
      my_putstr_color("red", "Ton sac est de très mauvaise qualité ");
      my_putstr_color("red", "Oublie ton rêve ...\n");
      return (0);
    }
  bag->magic_box = 5;
  bag->magic_sup = 0;
  bag->magic_master = 0;
  bag->potion = 5;
  bag->super_champ = 0;
  bag->rupes = 420;
  bag->champ = 0;
  bag->combattant = NULL;
  game->bag = bag;
  my_putstr_color("green", "Vous avez obtenue 5 magic-box\n");
  my_putstr_color("green", "Vous avez obtenue 5 krakra-potions\n");
  my_putstr_color("green", "Voilà !\n");
  return (1);
}

int			init_character(t_game *game, char *argv)
{
  t_character		*character;

  my_putstr_color("green", "\nJe ne connais pas ton prénom !\n");
  if ((character = malloc(sizeof(t_character))) == NULL)
    {
      my_putstr_color("red", "Ton nom à l'air plutot bizarre...\n");
      my_putstr_color("red", "Je refuse désolé...\n");
      return (0);
    }
  character->name = argv;
  character->bool = 0;
  character->bool_m = 0;
  character->etat = 1;
  character->etat_quit = 1;
  game->character = character;
  my_putstr_color("yellow", "Je m'appel ");
  my_putstr_color("yellow", character->name);
  my_putstr_color("green", "\nBien ! En avant !\n");
  my_putstr("\n");
  return (1);
}

int			init_friend(t_game **game)
{
  t_friend		*friend;

  if ((friend = malloc(sizeof(t_friend))) == NULL)
    {
      my_putstr_color("red", "Heiiin, une est survenue avec ");
      my_putstr_color("red", "nos krakramon, on vas devoir s'arreter ");
      my_putstr_color("red", "là :)\n");
      return (0);
    }
  friend->first = NULL;
  friend->last = NULL;
  friend->nb_elem = 0;
  friend->vivant = 1;
  (*game)->friend = friend;
  return (1);
}
