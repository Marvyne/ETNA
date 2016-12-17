/*
** sdl.c for  in /home/kirito/etna/bfm/copie/Final/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Fri Dec  9 04:22:43 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 11:20:52 2016 TOKPAHOLOU Marvyne
*/

#include "../include/my.h"
#include <SDL/SDL.h>

int                     init_sdl()
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    my_putstr(SDL_GetError());
  return (1);
}

int                     init_windows()
{
  SDL_Surface           *ecran;
  SDL_Surface           *img;
  SDL_Rect              positionFond;

  positionFond.x = 0;
  positionFond.y = 0;
  ecran = NULL;
  img = NULL;
  ecran = SDL_SetVideoMode(1000, 563, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Yousse_s etna piscine / MY_FTL", NULL);
  img = SDL_LoadBMP("src/pokemon.bmp");
  SDL_BlitSurface(img, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  SDL_Delay(2000);
  SDL_FreeSurface(img);
  return (1);
}

int                     init_windows1()
{
  SDL_Surface           *ecran;
  SDL_Surface           *img;
  SDL_Rect              positionFond;

  positionFond.x = 0;
  positionFond.y = 0;
  ecran = NULL;
  img = NULL;
  ecran = SDL_SetVideoMode(1000, 563, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Yousse_s etna piscine / bfm", NULL);
  img = SDL_LoadBMP("src/superball.bmp");
  SDL_BlitSurface(img, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  SDL_Delay(2000);
  SDL_FreeSurface(img);
  return (1);
}

int                     run_sdl()
{
  init_sdl();
  init_windows();
  SDL_Quit();
  return (1);
}

int                     run_sdl1()
{
  init_sdl();
  init_windows1();
  SDL_Quit();
  return (1);
}
