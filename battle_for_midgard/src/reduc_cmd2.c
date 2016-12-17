/*
** reduc_cmd2.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 23:46:36 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 03:05:01 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int		rand_rup(int a, int b)
{
  return (rand() % (b - a) + a);
}

int		rup_v(t_game *game)
{
  int		rnd;

  rnd = rand_rup(90, 120);
  my_putstr_color("green", "Vous gagnez : ");
  my_put_nbr(rnd);
  my_putstr_color("green", " Rupes");
  my_putstr("\n");
  game->bag->rupes += rnd;
  return (0);
}

int		reduc_cmd2(t_game *game, int msg)
{
  if (msg == 1)
    {
      my_putstr_color("blue", "lance l'attaque : SLASH\n");
      my_putstr_color("blue", "Perd : 15 PDV\n Perd : 3 PM\n");
      game->rival->pv -= 15;
      game->rival->pm -= 3;
    }
  else if (msg == 2)
    {
      my_putstr_color("red", "Vous avez vaincu l'enemie\n");
      rnd_sup(game);
      rnd_master(game);
      rup_v(game);
    }
  else if (msg == 3)
    {
      my_putstr_color("red", "Vous ne pouvez utilisez vos krakramon hors ");
      my_putstr_color("red", "des combats\n");
    }
  return (0);
}

int		reduc_cmd22(t_game *game, int msg)
{
  if (msg == 1)
    {
      my_putstr_color("blue", "lance l'attaque : FIRE\n");
      my_putstr_color("blue", "Perd : 30 PDV\nPerd : 7 PM\n");
      game->rival->pv -= 30;
      game->rival->pm -= 7;
    }
  else if (msg == 2)
    {
      my_putstr_color("red", "Vous avez vaincu l'enemi\n");
      game->character->etat = 0;
      rnd_sup(game);
      rnd_master(game);
      rup_v(game);
    }
  else if (msg == 3)
    {
      my_putstr_color("red", "Vous ne pouvez utilisez vos krakramon hors ");
      my_putstr_color("red", "des combats\n");
    }
  return (0);
}

int		reduc_cmd222(t_game *game, int msg)
{
  if (msg == 1)
    {
      my_putstr_color("blue", "lance l'attaque : GAMBLE\n");
      rnd_attaque(game);
      attack_monster(game);
    }
  else if (msg == 2)
    {
      my_putstr_color("red", "Vous avez vaincu l'enemi\n");
      game->character->etat = 0;
      rup_v(game);
      rnd_sup(game);
      rnd_master(game);
      game->character->etat_quit = 0;
    }
  else if (msg == 3)
    {
      my_putstr_color("red", "Vous ne pouvez utilisez vos krakramon hors ");
      my_putstr_color("red", "des combats\n");
    }
  return (0);
}
