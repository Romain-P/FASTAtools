/*
** str_reverse.c for  in /home/romain.pillot/projects/ADM_palindrome_2016/src/util/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 14:10:04 2017 romain pillot
** Last update Thu Jun 15 14:21:11 2017 romain pillot
*/

#include "util.h"

char	*str_reverse(char *str)
{
  int	a;
  int	b;
  int	mid;
  char	tmp;

  a = (b = 0);
  while (str && str[b] && ++b);
  mid = (--b) / 2 + 1;
  while (str && a != mid)
    {
      tmp = str[a];
      str[a++] = str[b];
      str[b--] = tmp;
    }
  return (str);
}
