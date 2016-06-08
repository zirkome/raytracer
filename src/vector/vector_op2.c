/*
** vector_op2.c for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:14:54 2013 guillaume fillon
** Last update Sun Jun  9 14:15:21 2013 guillaume fillon
*/

#include "vector.h"

double		get_angle(t_vector vec1, t_vector vec2)
{
  return (dot_product(vec1, vec2) / (get_norm(vec1) * get_norm(vec2)));
}

t_vector	vec_reflective(t_vector vec, t_vector n)
{
  double	scal;
  t_vector	r;

  n = normalize(n);
  vec = normalize(vec);
  scal = -2.0 * dot_product(vec, n);
  r = sum_vector(scale_vector(n, scal), vec);
  return (r);
}
