/*
** str_replace.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src/util/str
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 12:35:57 2017 romain pillot
** Last update Mon Jun 19 12:37:45 2017 romain pillot
*/

char	*str_replace(char *str, const char target, const char new)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == target)
      str[i] = new;
  return (str);
}
