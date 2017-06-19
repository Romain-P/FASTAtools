/*
** list.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 09:55:41 2017 romain pillot
** Last update Mon Jun 19 19:28:38 2017 romain pillot
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tool.h"
#include "util.h"

void		write_kmer(t_sequence **seqs, int k)
{
  t_array	*array;
  int		i;
  int		j;
  char		*tmp;

  array = array_create();
  while (*seqs++ && (i = 1))
    while ((j = -1) && seqs[-1]->data[++i])
      {
	if (str_length(seqs[-1]->data + i) < k ||
	    !(tmp = malloc(sizeof(char) * (k + 1))))
	  break;
	tmp[k] = 0;
	while (++j < k)
	  tmp[j] = seqs[-1]->data[i + j];
	if (!tab_contains((char **) array->values, tmp))
	  array_add(array, strdup(tmp));
	free(tmp);
      }
  tab_sort((char **) array->values);
  while (++j < array->length)
    printf("%s\n", array->values[j]);
  array_destroy(&array, true);
}

static bool	codon_end(char *str)
{
  return (str_starts(str, "TTA") ||
	  str_starts(str, "TAG") ||
	  str_starts(str, "TGA"));
}

/* memory leak.. fkin norm, I NEED 2 LINES MORE*/
static void	search_sequence(char *str)
{
  int		i;
  bool		valid;
  char		*seq;
  char		*tmp;

  i = 0;
  valid = false;
  seq = (tmp = NULL);
  while (str[i] && strlen(str + i) >= 3)
    {
      if (valid && seq && str_contains(seq + 3, "ATG") && !(valid = false))
	{
	  i -= strlen(seq) - 2;
	  FREE(seq);
	}
      else if (str_starts(str + i, "ATG"))
	valid = (seq = strdup("ATG"));
      else if ((seq && codon_end(str + i) && !(valid = false)))
	printf("%s\n", seq);
      else if (valid)
	seq = str_concat(seq, (tmp = str_dupli(str + i, 3)), true);
      FREE(tmp);
      i += valid ? 3 : 1;
    }
}

void	write_coded(t_sequence **seqs, int k)
{
  int	i;
  bool	display;
  char	*str;

  (void) k;
  while (*seqs++)
    search_sequence(seqs[-1]->data);
}

void	write_acids(t_sequence **seqs, int k)
{
  (void) k;
}
