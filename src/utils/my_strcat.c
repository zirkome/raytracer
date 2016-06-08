/*
** my_strcat.c for RT in /home/fillon_g/projets/raytracer/refactor/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Apr 22 17:48:44 2013 guillaume fillon
** Last update Sun Jun  9 14:48:15 2013 guillaume fillon
*/

#include "utils.h"

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	len_src;

  i = -1;
  len_src = my_strlen(s1);
  while (s2[++i])
    s1[len_src + i] = s2[i];
  s1[len_src + i] = '\0';
  return (s1);
}
