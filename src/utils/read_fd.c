/*
** read_fd.c for read_fd.c in /home/bridou_n//minishell1/Bonus
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Thu Dec 13 15:38:55 2012 nicolas bridoux
** Last update Sun Jun  9 14:44:08 2013 guillaume fillon
*/

#include "utils.h"

char		*read_fd(const int fd)
{
  char		*ret;
  struct stat	p;

  if (fstat(fd, &p) == -1)
    return (NULL);
  if (!(ret = malloc(sizeof(char) * (p.st_size + 1))))
    return (NULL);
  if (read(fd, ret, p.st_size * sizeof(char)) < p.st_size)
    {
      free(ret);
      return (NULL);
    }
  ret[p.st_size] = '\0';
  return (ret);
}
