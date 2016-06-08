/*
** my_strlen.c for RT in /home/fillon_g/projets/raytracer/refactor/src/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Apr 23 01:54:30 2013 guillaume fillon
** Last update Sun Jun  9 14:45:56 2013 guillaume fillon
*/

#include "utils.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

int	len_tab(void **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    ;
  return (i);
}
