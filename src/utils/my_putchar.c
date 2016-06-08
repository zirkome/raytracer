/*
** my_putchar.c for my_putchar.c in /home/bridou_n//Jour_07
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Tue Oct  9 09:33:48 2012 nicolas bridoux
** Last update Sun Jun  9 14:47:05 2013 guillaume fillon
*/

#include "utils.h"

void	my_putchar(char c)
{
  if ((write(1, &c, sizeof(char))) == -1)
    exit(EXIT_FAILURE);
}
