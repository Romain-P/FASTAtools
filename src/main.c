/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Mon Jun 19 14:15:14 2017 romain pillot
*/

#include <stdio.h>
#include <stdlib.h>
#include "tool.h"
#include "util.h"
#include "array.h"

static void	(* const g_mode[])(t_sequence **seqs, int k) =
{
  &write_dna,
  &write_rna,
  &write_reversed,
  &write_kmer,
  &write_coded,
  &write_acids,
  &write_aligned
};

bool	parse_options(int opts[2], int ac, char **args)
{
  int	option;

  if (ac < 2 || ac > 3 ||
      (option = atoi(args[1])) < 1 || option > 7 ||
      (option != 4 && ac != 2))
    return (false);
  opts[0] = option - 1;
  opts[1] = args[2] ? atoi(args[2]) : -1;
  return (option == 4 ? opts[1] != -1 : true);
}
  
int		main(int ac, char **args)
{
  t_array	*array;
  t_sequence	**sequences;
  int		options[2];

  if (!parse_options(options, ac, args) ||
      !(array = parse_sequences()) || !array->length)
    return (_EXIT_FAILURE);
  sequences = (t_sequence **) array->values;
  g_mode[options[OPT_MODE]](sequences, options[OPT_K]);
  while (*sequences)
    {
      FREE((*sequences)->name);
      FREE((*sequences)->data);
      FREE((*sequences++));
    }
  array_destroy(&array, false);
  return (_EXIT_SUCCESS);
}
