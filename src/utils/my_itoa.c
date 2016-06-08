/*
** my_itoa.c for RTv1 in /home/fillon_g/projets/rtv1/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Mar 17 16:07:35 2013 guillaume fillon
** Last update Sun Jun  9 16:15:42 2013 guillaume fillon
*/

#include "utils.h"

char	*my_itoa(int i, char *b)
{
  int	shifter;
  char	*p;

  shifter = i;
  p = b;
  if (i < 0)
    {
      *p++ = '-';
      i = -1;
    }
  shifter = i;
  while (shifter)
    {
      ++p;
      shifter = shifter / 10;
    }
  *p = '\0';
  while (i)
    {
      *--p = DECIMAL[i % 10];
      i = i / 10;
    }
  return (b);
}
