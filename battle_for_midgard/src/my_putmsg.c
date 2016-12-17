/*
** my_putmsg.c for  in /home/kirito/etna/ftl/yousse_s
** 
** Made by YOUSSEF seif-eddine
** Login   <yousse_s@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:25:04 2016 YOUSSEF seif-eddine
** Last update Mon Dec  5 11:02:28 2016 YOUSSEF seif-eddine
*/

#include "../include/my.h"

void		my_putmsg_r(char *str)
{
  my_putstr("\033[31m\033[1m\033[4m\033[5m\033[7m");
  my_putstr(str);
  my_putstr("\033[0m");
}

void		my_putmsg_g(char *str)
{
  my_putstr("\033[32m\033[1m\033[4m\033[5m\033[7m");
  my_putstr(str);
  my_putstr("\033[0m");
}

void		my_putmsg_y(char *str)
{
  my_putstr("\033[33m\033[1m\033[4m\033[5m\033[7m");
  my_putstr(str);
  my_putstr("\033[0m");
}

void		my_putmsg_b(char *str)
{
  my_putstr("\033[34m\033[1m\033[4m\033[5m\033[7m");
  my_putstr(str);
  my_putstr("\033[0m");
}
