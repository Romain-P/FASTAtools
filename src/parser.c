/*
** parser.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 07:42:06 2017 romain pillot
** Last update Mon Jun 19 09:26:51 2017 romain pillot
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "tool.h"
#include "util.h"
#include "array.h"

static const char sequences[] = {
  'A',
  'T',
  'G',
  'C',
  'N',
  0
};

static bool	valid_char(char c)
{
  int		i;

  i = -1;
  while (sequences[++i])
    if (sequences[i] == c)
      return (true);
  return (false);
}

static int	count_valid_chars(char const *str)
{
  int		i;
  int		j;

  i = 0;
  j = -1;
  while (str[++j])
    if (valid_char(str[j]))
      i++;
  return (i);
}

static void	fill_sequence(t_sequence *sequence, char const *str)
{
  int		len;
  char		*cleared;
  int		i;
  int		j;

  len = count_valid_chars(str);
  if (!(cleared = malloc(sizeof(char) * (len + 1))))
    return ;
  cleared[len] = 0;
  i = -1;
  j = -1;
  while (str[++i])
    if (valid_char(str[i]))
      cleared[++j] = str[i];
  if (*cleared)
    sequence->data = str_concat(sequence->data, cleared, false);
  free(cleared);
}

t_array		*parse_sequences()
{
  char		*str;
  t_array	*array;
  t_sequence	*sequence;

  array = array_create();
  while ((str = scan_line(STDIN_FILENO)))
    {
      if (*str == LINE_SEQ_NAME)
	{
	  if (!(sequence = malloc(sizeof(t_sequence))))
	    return (array);
	  sequence->name = strdup(str + 1);
	  array_add(array, sequence);
	}
      else if (sequence)
	fill_sequence(sequence, str);
      FREE(str);
    }
  return (array);
}
