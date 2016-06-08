/*
** my_strcmp.c for my_strcmp.c in /home/bridou_n//Jour_06
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Mon Oct  8 14:08:56 2012 nicolas bridoux
** Last update Sun Jun  9 14:48:26 2013 guillaume fillon
*/

#include "utils.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (i < my_strlen(s1) || i < my_strlen(s2))
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
	return (1);
      ++i;
    }
  if (s1[i] == s2[i])
    return (0);
  return (0);
}
