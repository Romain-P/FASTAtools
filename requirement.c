/*
** requirement.c for  in /home/romain.pillot/projects/ADM_palindrome_2016
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Jun 15 07:05:30 2017 romain pillot
** Last update Mon Jun 19 14:44:12 2017 romain pillot
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

static bool	alpha_num(char c)
{
  return (uppercase(c) || lowercase(c) ||
	  (c >= '0' && c <= '9'));
}

char	*my_strcapitalize_synthesis(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    if ((!i || !alpha_num(str[i - 1])) && lowercase(str[i]))
      str[i] = str[i] - 'a' + 'A';
    else if (i && alpha_num(str[i - 1]) && uppercase(str[i]))
      str[i] = str[i] - 'A' + 'a';
  return (str);
}
