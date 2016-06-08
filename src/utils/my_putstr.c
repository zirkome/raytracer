/*
** my_putstr.c for RT in /home/fillon_g/projets/raytracer/refactor/src/utils
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Apr 23 01:53:56 2013 guillaume fillon
** Last update Sun Jun  9 16:15:12 2013 guillaume fillon
*/

#include "utils.h"

void	my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str) * sizeof(char))) == -1)
    exit(EXIT_FAILURE);
}
