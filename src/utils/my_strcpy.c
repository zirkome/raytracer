/*
** my_strcpy.c for RT in /home/fillon_g/projets/raytracer/refactor/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Apr 22 17:47:30 2013 guillaume fillon
** Last update Sun Jun  9 14:48:38 2013 guillaume fillon
*/

#include "utils.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
