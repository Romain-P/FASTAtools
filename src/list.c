/*
** list.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 09:55:41 2017 romain pillot
** Last update Mon Jun 19 13:31:51 2017 romain pillot
*/

#include <stdio.h>
#include "tool.h"
#include "util.h"

void	write_reversed(t_sequence **seqs, int k)
{
  int	i;
  char	c;

  while (*seqs++)
    {
      printf("%s\n", seqs[-1]->name);
      i = -1;
      while ((c = seqs[-1]->data[++i]))
        seqs[-1]->data[i] =
	  c == 'A' ? 'T' :
	  c == 'T' ? 'A' :
	  c == 'G' ? 'C' :
	  c == 'C' ? 'G' : c;
      printf("%s\n", str_reverse(seqs[-1]->data));
    }
}

void	write_kmer(t_sequence **seqs, int k)
{
  (void) k;
}

void	write_coded(t_sequence **seqs, int k)
{
  (void) k;
}

void	write_acids(t_sequence **seqs, int k)
{
  (void) k;
}
