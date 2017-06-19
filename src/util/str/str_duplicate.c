/*
** str_duplicate.c for  in /home/romain.pillot/projects/ghoulc/src/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Sun May 28 03:24:50 2017 romain pillot
** Last update Mon Jun 19 16:50:28 2017 romain pillot
*/

#include <stdlib.h>
#include "util.h"

char	*str_dupl(const char *str)
{
  char  *new;
  char  *hold;

  if (!(hold = (new = malloc(sizeof(char) * (str_length(str) + 1)))))
    return (NULL);
  while (*str)
    *new++ = *str++;
  *new = 0;
  return (hold);
}

char	*str_dupli(const char *str, int len)
{
  char  *new;
  int	i;

  if (!(new = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  new[len] = 0;
  i = -1;
  while (++i < len)
    new[i] = str[i];
  return (new);
}
