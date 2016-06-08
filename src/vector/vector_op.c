/*
** vector.c for raytracer in /home/collin_b//rererererere
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Thu May 30 14:36:10 2013 jonathan collinet
** Last update Sun Jun  9 14:15:29 2013 guillaume fillon
*/

#include "vector.h"

t_vector	scale_vector(t_vector vec, double k)
{
  vec.x = vec.x * k;
  vec.y = vec.y * k;
  vec.z = vec.z * k;
  return (vec);
}

t_vector	sum_vector(t_vector v1, t_vector v2)
{
  t_vector	new;

  new.x = v1.x + v2.x;
  new.y = v1.y + v2.y;
  new.z = v1.z + v2.z;
  return (new);
}

t_vector	sub_vector(t_vector v1, t_vector v2)
{
  t_vector	new;

  new.x = v1.x - v2.x;
  new.y = v1.y - v2.y;
  new.z = v1.z - v2.z;
  return (new);
}

t_vector	mult_vector(t_vector v1, t_vector v2)
{
  t_vector	new;

  new.x = v1.x * v2.x;
  new.y = v1.y * v2.y;
  new.z = v1.z * v2.z;
  return (new);
}
