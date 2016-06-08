/*
** my_strncmp.c for RT in /home/fillon_g/projets/raytracer/refactor/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Apr 22 17:47:55 2013 guillaume fillon
** Last update Sun Jun  9 14:45:45 2013 guillaume fillon
*/

#include "utils.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  while (++i < n)
    {
      if (s1[i] < s2[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
    }
  if (s1[i] == s2[i])
    return (0);
  return (0);
}
