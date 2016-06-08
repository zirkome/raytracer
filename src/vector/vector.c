/*
** vector.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 00:30:21 2013 guillaume fillon
** Last update Sun Jun  9 15:43:38 2013 guillaume fillon
*/

#include <math.h>
#include "vector.h"

t_vector	new_vector(double x, double y, double z)
{
  t_vector	v;

  v.x = x;
  v.y = y;
  v.z = z;
  return (v);
}

t_vector	eq_parametric(t_vector v1, t_vector v2, double k)
{
  t_vector	new;

  new.x = v1.x + k * v2.x;
  new.y = v1.y + k * v2.y;
  new.z = v1.z + k * v2.z;
  return (new);
}

double		dot_product(t_vector v1, t_vector v2)
{
  return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

double		get_norm(t_vector vec)
{
  return (sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0)));
}

t_vector	normalize(t_vector vec)
{
  double	norm;

  norm = get_norm(vec);
  vec.x = vec.x / norm;
  vec.y = vec.y / norm;
  vec.z = vec.z / norm;
  return (vec);
}
