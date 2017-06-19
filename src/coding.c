/*
** list.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 09:55:41 2017 romain pillot
** Last update Mon Jun 19 21:03:22 2017 romain pillot
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tool.h"
#include "util.h"

static t_amino const g_acids[] =
{
  (t_amino) {'A', (char *[])  {"GCT", "GCC", "GCA", "GCG", NULL}},
  (t_amino) {'C', (char *[]) {"TGT", "TGC", NULL}},
  (t_amino) {'D', (char *[]) {"GAT", "GAC", NULL}},
  (t_amino) {'E', (char *[]) {"GAA", "GAG", NULL}},
  (t_amino) {'F', (char *[]) {"TTT", "TTC", NULL}},
  (t_amino) {'G', (char *[]) {"GGT", "GGC", "GGA", "GGG", NULL}},
  (t_amino) {'H', (char *[]) {"CAT", "CAC", NULL}},
  (t_amino) {'I', (char *[]) {"ATT", "ATC", "ATA", NULL}},
  (t_amino) {'K', (char *[]) {"AAA", "AAG", NULL}},
  (t_amino) {'L', (char *[]) {"TTA", "TTG", "CTT", "CTC", "CTA", "CTG", 0}},
  (t_amino) {'M', (char *[]) {"ATG", NULL}},
  (t_amino) {'N', (char *[]) {"AAT", "AAC", NULL}},
  (t_amino) {'P', (char *[]) {"CCT", "CCC", "CCA", "CCG", NULL}},
  (t_amino) {'Q', (char *[]) {"CCA", "CAG", NULL}},
  (t_amino) {'R', (char *[]) {"AGA", "AGG", "CGT", "CGC", "CGA", "CGG", 0}},
  (t_amino) {'S', (char *[]) {"TCT", "TCC", "TCA", "TCG", "AGT", "AGC", 0}},
  (t_amino) {'T', (char *[]) {"ACT", "ACC", "ACA", "ACG", NULL}},
  (t_amino) {'V', (char *[]) {"GTT", "GTC", "GTA", "GTG", NULL}},
  (t_amino) {'W', (char *[]) {"TGG", NULL}},
  (t_amino) {'X', NULL},
  (t_amino) {'Y', (char *[]) {"TAT", "TAC", NULL}},
  (t_amino) {0, NULL}
};

static bool	codon_end(char *str)
{
  return (str_starts(str, "TTA") ||
	  str_starts(str, "TAG") ||
	  str_starts(str, "TGA"));
}

static char	*convert_protein(char *seq)
{
  char		*prot;
  char		*tmp;
  int		i;
  int		j;
  int		k;
  int		len;

  prot = malloc(sizeof(char) * ((len = (strlen(seq) / 3)) + 1));
  prot[len] = 0;
  i = (j = 0);
  while (seq && i <= strlen(seq) && seq[i])
    {
      tmp = str_dupli(seq + i, 3);
      if (str_contains(tmp, "N"))
	prot[j++] = 'X';
      else if ((k = -1))
	while (g_acids[++k].id)
	  if (tab_contains(g_acids[k].codons, tmp))
	    prot[j++] = g_acids[k].id;
      FREE(tmp);
      i += 3;
    }
  return (prot);
}

static void	search_sequence(char *str, t_array *array)
{
  int		i;
  bool		valid;
  char		*seq;
  char		*tmp;

  i = 0;
  valid = false;
  seq = (tmp = NULL);
  while (i <= strlen(str) && str[i] && strlen(str + i) >= 3)
    {
      if (valid && seq && str_contains(seq + 3, "ATG") && !(valid = false))
	{
	  i -= strlen(seq) - 2;
	  FREE(seq);
	}
      else if (str_starts(str + i, "ATG"))
	valid = (seq = strdup("ATG"));
      else if ((seq && codon_end(str + i) && !(valid = false)))
	(!array ? printf("%s\n", seq) : array_add(array, convert_protein(seq)));
      else if (valid)
	seq = str_concat(seq, (tmp = str_dupli(str + i, 3)), true);
      FREE(tmp);
      i += valid ? 3 : 1;
    }
}

void	write_coded(t_sequence **seqs, int k)
{
  (void) k;
  while (*seqs++)
    search_sequence(seqs[-1]->data, NULL);
}

void		write_acids(t_sequence **seqs, int k)
{
  t_array	*array;
  int		i;

  array = array_create();
  (void) k;
  while (*seqs++)
    search_sequence(seqs[-1]->data, array);
  tab_sort((char **) array->values);
  i = -1;
  while (++i < array->length)
    printf("%s\n", array->values[i]);
  array_destroy(&array, true);
}
