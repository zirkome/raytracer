/*
** arithmetic.c for raytracer in /home/collin_b//raytracer-2017-bridou_n/new
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Sun Jun  2 23:51:27 2013 jonathan collinet
** Last update Sun Jun  9 14:44:15 2013 guillaume fillon
*/

#include "utils.h"

double	modulo(double nb1, double nb2)
{
  return (nb1 - ((nb1 / nb2) * nb2));
}

void	shift(char *str, int i)
{
  while (str[i])
    {
      str[i] = str[i + 1];
      ++i;
    }
}

char	double_are_same(double a, double b)
{
  return (fabs(a - b) < EPSILON);
}
