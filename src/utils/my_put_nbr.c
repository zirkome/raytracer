/*
** my_put_nbr.c for RT in /home/fillon_g/projets/raytracer/refactor/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Apr 23 01:58:52 2013 guillaume fillon
** Last update Sun Jun  9 14:46:48 2013 guillaume fillon
*/

#include "utils.h"

void	my_put_nbr(int nb)
{
  int	modulo;
  int	div;

  if (nb < 0 && nb > -10)
    my_putchar('-');
  modulo = nb % 10;
  div = nb / 10;
  if (nb >= 10 || nb <= -10)
    my_put_nbr(div);
  if (modulo < 0)
    modulo = - modulo;
  my_putchar(modulo + '0');
}
