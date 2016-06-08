/*
** my_strdup.c for RT in /home/fillon_g/projets/raytracer/refactor/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Apr 22 17:48:23 2013 guillaume fillon
** Last update Sun Jun  9 16:15:18 2013 guillaume fillon
*/

#include "utils.h"

char	*my_strdup(char *src)
{
  char	*str;
  int	len;

  len = my_strlen(src);
  if (!(str = malloc(sizeof(char) * (len + 1))))
    my_error("Not enough memory\n", 1);
  my_strcpy(str, src);
  return (str);
}
