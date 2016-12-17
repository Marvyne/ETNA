/*
** my_put_nbr.c for my_put_nbr.c in /home/marvyne/repertoire_rendu/j05c/tokpah_m/my_put_nbr
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Sat Oct 22 13:51:14 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 11:21:54 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

void	my_put_nbr(int n)
{
  int	nbunite;
  int	ent;

  nbunite = 1;
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  ent = n;
  while (ent > 9)
    {
      ent = ent / 10;
      nbunite = nbunite * 10;
    }
  while (nbunite > 0)
    {
      ent = n / nbunite ;
      my_putchar('0' + ent);
      n = n - ent * nbunite;
      nbunite = nbunite /10;
    }
}
