/*
** sdl.c for  in /home/kirito/etna/bfm/copie/Final/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Fri Dec  9 04:22:43 2016 YOUSSEF seif-eddine
** Last update Fri Dec  9 11:21:12 2016 TOKPAHOLOU Marvyne
*/

#include "../include/my.h"
#include <SDL/SDL.h>

int                     init_windows2()
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
  img = SDL_LoadBMP("src/masterball.bmp");
  SDL_BlitSurface(img, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  SDL_Delay(2000);
  SDL_FreeSurface(img);
  return (1);
}

int                     init_windows3()
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
  img = SDL_LoadBMP("source/champ.bmp");
  SDL_BlitSurface(img, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  SDL_Delay(2000);
  SDL_FreeSurface(img);
  return (1);
}

int                     init_windows4()
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
  img = SDL_LoadBMP("source/super_champ.bmp");
  SDL_BlitSurface(img, NULL, ecran, &positionFond);
  SDL_Flip(ecran);
  SDL_Delay(2000);
  SDL_FreeSurface(img);
  return (1);
}

int                     run_sdl2()
{
  init_sdl();
  init_windows2();
  SDL_Quit();
  return (1);
}

int                     run_sdl3()
{
  init_sdl();
  init_windows3();
  SDL_Quit();
  return (1);
}
