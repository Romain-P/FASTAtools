/*
** util.h for  in /home/romain.pillot/projects/ghoulc/inc
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Tue May 23 14:02:04 2017 romain pillot
** Last update Mon Jun 19 12:38:15 2017 romain pillot
*/

#ifndef UTIL_H_
# define UTIL_H_

# include <stdbool.h>

void	safe_free(void **ptr);

void	tab_free(void ***ptr);

# define FREE(PTR)      (safe_free((void **) &(PTR)))

# define TAB_FREE(PTR)	(tab_free((void ***) &(PTR)))

void	tab_sort(char **tab);

bool	tab_contains(char **tab, const char *str);

int	nbr_parsestring(const char *str);

bool	str_isnumber(const char *str);

char	*str_reverse(char *str);

char	*str_replace(char *str, const char target, const char new);

char	*str_concat(char *a, const char *b, bool free_a);

bool	str_contains(const char *str, const char *charset);

bool	str_equals(const char *a, const char *b);

bool	str_starts(const char *str, const char *charset);

int	str_length(const char *str);

int	tab_length(char **tab);

char	*str_dupl(const char *str);

int	str_countchar(const char *str, const char delimiter);

char	*str_reduce(char *str, const char delimiter);

char	**str_split(char *str, const char delimiter);

bool	print(const char *str);

bool	fprint(const char *str);

char	*scan_line(const int file);

#endif /* !UTIL_H_ */
