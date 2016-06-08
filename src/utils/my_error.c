/*
** my_error.c for RT in /home/fillon_g/projets/raytracer/refactor/src/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Apr 23 01:54:43 2013 guillaume fillon
** Last update Sun Jun  9 14:46:33 2013 guillaume fillon
*/

#include "utils.h"

void	my_error(char *str, int quit)
{
  if ((write(2, str, my_strlen(str) * sizeof(char))) == -1)
    exit(EXIT_FAILURE);
  if (quit)
    exit(EXIT_FAILURE);
}
