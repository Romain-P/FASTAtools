/*
** sequence.c for  in /home/romain.pillot/projects/ADM_FASTAtools_2016/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Jun 19 07:30:08 2017 romain pillot
** Last update Mon Jun 19 12:43:43 2017 romain pillot
*/

#include <stdlib.h>
#include <stdio.h>
#include "tool.h"
#include "util.h"

void	write_dna(t_sequence **seqs, int k)
{
  int	i;

  (void) k;
  while (*seqs++)
    printf("%s\n%s\n", seqs[-1]->name, seqs[-1]->data);
}

void	write_rna(t_sequence **seqs, int k)
{
  int   i;

  (void) k;
  while (*seqs++)
    printf("%s\n%s\n", seqs[-1]->name, str_replace(seqs[-1]->data, 'T', 'U'));
}

void	write_aligned(t_sequence **seqs, int k)
{
  (void) k;
}
