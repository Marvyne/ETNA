/*
1;2802;0c** free_me.c for  in /home/kirito/etna/bfm/tokpah_m/Etape_2
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Thu Dec  8 23:06:58 2016 YOUSSEF seif-eddine
** Last update Thu Dec  8 23:26:52 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

int                     free_me(t_game *game)
{
  if (game->rival!= NULL)
    free(game->rival);
  if (game->bag != NULL)
    free(game->bag);
  if (game->character != NULL)
    free(game->character);
  if (game->friend != NULL)
    free(game->friend);
  if (game != NULL)
    free(game);
  return (0);
}

int			free_me_too(t_game *game)
{
  free_me(game);
  return (0);
}
