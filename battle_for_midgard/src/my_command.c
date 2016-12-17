/*
** my_command.c for  in /home/kirito/etna/bfm/tokpah_m/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Tue Dec  6 13:16:15 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 05:26:38 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int                                     krakra_help(t_game *game)
{
  game->character->bool = 0;
  my_putstr_color("green", "Je suis là !\n");
  my_putstr_color("green", "Voici les commandes que tu peux utiliser\n");
  my_putstr_color("blue", "help me\n");
  my_putstr_color("blue", "magic catch\n");
  my_putstr_color("blue", "super-magic catch\n");
  my_putstr_color("blue", "master-magic catch\n");
  my_putstr_color("blue", "inventaire\n");
  my_putstr_color("blue", "krakra-help\n");
  my_putstr_color("blue", "quit\n");
  my_putstr_color("blue", "stat\n");
  my_putstr_color("blue", "magasin\n");
  my_putstr_color("blue", "buy champ\n");
  my_putstr_color("blue", "buy super-champ\n");
  my_putstr_color("blue", "buy super-magic boxt\n");
  my_putstr_color("blue", "buy magix box\n");
  my_putstr_color("blue", "use champ\n");
  my_putstr_color("blue", "use super-champ\n");
  my_putstr_color("blue", "fire\n");
  my_putstr_color("blue", "slash\n");
  my_putstr_color("blue", "gamble\n");
  my_putstr_color("blue", "rest\n");
  my_putstr_color("blue", "let's fight\n");
  my_putstr_color("blue", "team\n");
  return (0);
}

int                                     help_me(t_game *game)
{
  if (game->character->bool_m == 0 && game->character->etat_quit == 1)
    {
      my_putstr_color("red", "Vous fuyer le combat ");
      my_putstr_color("red", "mais un nouveaux monstre apparait.\n");
      ajout_rival(game);
    }
  else if (game->character->bool_m == 1)
    {
      my_putstr_color("red", "Krakra master : Eh oh !\n");
      my_putstr_color("red", "Tu ne peux demander de l'aide si ");
      my_putstr_color("red", "tu n'as personne en face de toi !\n");
    }
  return (0);
}

int                                     inventaire(t_game *game)
{
  inventaire_ch(game);
  if (game->bag->magic_sup > 0)
    {
      my_putstr_color("yellow", "Super-Magic box : ");
      my_put_nbr(game->bag->magic_sup);
      my_putchar('\n');
    }
  if (game->bag->magic_master > 0)
    {
      my_putstr_color("yellow", "Master-magic box : ");
      my_put_nbr(game->bag->magic_master);
      my_putchar('\n');
    }
  return (0);
}

int                                     quit(t_game *game)
{
  if (game->character->etat_quit == 0)
    {
      my_putstr_color("green", "A bientot jeune aventurier !\n");
      game->character->bool = 1;
    }
  if (game->character->etat_quit == 1)
    {
      game->character->bool_m = 0;
      my_putstr_color("green", "Vous fuyé lachement !\n");
      game->character->etat = 0;
      etat(game);
    }
  return (0);
}
