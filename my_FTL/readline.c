/*
** readline.c for readline.c in /home/marvyne/repertoire_rendu/chifumi/tokpah_m/chifumi
** 
** Made by TOKPAHOLOU Marvyne
** Login   <tokpah_m@etna-alternance.net>
** 
** Started on  Thu Oct 27 06:42:34 2016 TOKPAHOLOU Marvyne
** Last update Sat Nov 12 11:48:16 2016 TOKPAHOLOU Marvyne
*/

#include "ftl.h"

char		*readline()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
