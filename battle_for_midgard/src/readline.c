/*
** readline.c for  in /home/kirito/etna/bfm/src
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Mon Dec  5 10:50:27 2016 YOUSSEF seif-eddine
** Last update Mon Dec  5 11:01:59 2016 YOUSSEF seif-eddine
*/
#include	"../include/my.h"
#include        <stdlib.h>
#include        <unistd.h>

char            *readline(void)
{
  ssize_t       ret;
  char          *buff;

  if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  free(buff);
  return (NULL);
}
