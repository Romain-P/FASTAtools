/*
** sequence.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 07:30:08 2017 romain pillot
** Last update Mon Jun 19 17:07:42 2017 romain pillot
*/

#include <stdlib.h>
#include <stdio.h>
#include "tool.h"
#include "util.h"

void	write_dna(t_sequence **seqs, int k)
{
  (void) k;
  while (*seqs++)
    printf("%s\n%s\n", seqs[-1]->name, seqs[-1]->data);
}

void	write_rna(t_sequence **seqs, int k)
{
  while (*seqs++)
    printf("%s\n%s\n", seqs[-1]->name, str_replace(seqs[-1]->data, 'T', 'U'));
}

void    write_reversed(t_sequence **seqs, int k)
{
  int   i;
  char  c;

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

void	write_aligned(t_sequence **seqs, int k)
{
  (void) k;
}
