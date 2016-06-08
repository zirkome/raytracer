/*
** my_realloc.c for RT in /home/fillon_g/projets/raytracer/refactor/parser
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Apr 22 17:54:34 2013 guillaume fillon
** Last update Sun Jun  9 14:47:27 2013 guillaume fillon
*/

#include "utils.h"

char	*my_realloc(char *str, int size, int *j)
{
  int	i;
  char	*buffer;

  i = 0;
  str[*j * READ + READ] = '\0';
  if ((buffer = malloc(sizeof(char) * ((*j * READ + READ) + (size + 1))))
      == NULL)
    my_error("Can't perform malloc\n", 1);
  while (str[i] != '\0')
    {
      buffer[i] = str[i];
      ++i;
    }
  buffer[i] = '\0';
  free(str);
  return (buffer);
}
