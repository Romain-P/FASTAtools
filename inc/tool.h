/*
** main.h for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:15:51 2016 romain pillot
** Last update Mon Jun 19 20:35:27 2017 romain pillot
*/

#ifndef TOOL_H_
# define TOOL_H_

# define _EXIT_FAILURE	(84)
# define _EXIT_SUCCESS	(0)

# define LINE_SEQ_NAME	('>')
# define OPT_MODE	(0)
# define OPT_K		(1)

# include "array.h"

typedef struct	s_sequence
{
  char		*name;
  char		*data;
}		t_sequence;

typedef struct	s_amino
{
  char const	id;
  char		**codons;
}		t_amino;

t_array	*parse_sequences();

void	write_dna(t_sequence **seqs, int k);

void	write_rna(t_sequence **seqs, int k);

void	write_aligned(t_sequence **seqs, int k);

void	write_reversed(t_sequence **seqs, int k);

void	write_kmer(t_sequence **seqs, int k);

void	write_coded(t_sequence **seqs, int k);

void	write_acids(t_sequence **seqs, int k);

#endif /** !TOOL_H_ **/
