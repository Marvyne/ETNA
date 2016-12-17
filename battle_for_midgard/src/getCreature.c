/*
** getCreature.c for  in /home/kirito/etna/bfm/tokpah_m/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Tue Dec  6 09:44:37 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 00:10:38 2016 YOUSSEF seif-eddine
*/

#include <stdlib.h>
#include "../include/my.h"

static t_creature g_creatures[] =
  {
    {"Koopa" , 1, 100, 100, 50, 50, NULL, NULL},
    {"Bob bomb", 1, 100, 100, 50, 50, NULL, NULL},
    {"Yoshi", 1, 100, 100, 50, 50, NULL, NULL},
    {"Maskas", 1, 100, 100, 50, 50, NULL, NULL},
    {"Kucco", 1, 100, 100, 50, 50, NULL, NULL},
    {NULL, 0, 0, 0, 0, 0, NULL, NULL}
  };

t_creature	*getCreature()
{
  int		rnd;
  t_creature	*crea;

  rnd = rand() % NBCREA;
  if ((crea = malloc(sizeof(t_creature))) == NULL)
    return (NULL);
  crea->name = my_strdup(g_creatures[rnd].name);
  if (!crea->name)
    return (NULL);
  crea->lvl = g_creatures[rnd].lvl;
  crea->pv = g_creatures[rnd].pv;
  crea->pvmax = g_creatures[rnd].pvmax;
  crea->pm = g_creatures[rnd].pm;
  crea->pmmax = g_creatures[rnd].pmmax;
  crea->prev = g_creatures->prev;
  crea->next = g_creatures->next;
  return (crea);
}
