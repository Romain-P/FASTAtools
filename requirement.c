/*
** requirement.c for  in /home/romain.pillot/projects/ADM_palindrome_2016
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 07:05:30 2017 romain pillot
** Last update Mon Jun 19 07:18:21 2017 romain pillot
*/

#include <stdlib.h>
#include <stdbool.h>

static bool	uppercase(char c)
{
  return (c >= 'A' && c <= 'Z');
}

static bool	lowercase(char c)
{
  return (c >= 'a' && c <= 'z');
}

char	*my_strcapitalize_synthesis(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if ((!i || str[i - 1] == ' ') && lowercase(str[i]))
      str[i] = str[i] - 'a' + 'A';
    else if (i && str[i - 1] != ' ' && uppercase(str[i]))
      str[i] = str[i] - 'A' + 'a';
  return (str);
}
