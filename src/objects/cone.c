/*
** cone.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 02:21:58 2013 guillaume fillon
** Last update Sun Jun  9 16:15:50 2013 freddy sallaberry
*/

#include "raytracer.h"
#include "object.h"
#include "utils.h"

t_vector	normal_cone(UNUSED t_cam *eye, UNUSED t_obj *obj, t_vector p)
{
  return (new_vector(p.x, p.y, p.z * 0.6));
}

double		inter_cone(t_cam *eye, t_obj *o)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	tan_square;
  double	k;
  t_vector	p;

  tan_square = pow(tan(o->size), 2.0);
  a = pow(eye->v.x, 2.0)
    + (pow(eye->v.y, 2.0))
    - (pow(eye->v.z, 2.0) / tan_square);
  b = (2.0 * eye->pos.x * eye->v.x)
    + (2.0 * eye->pos.y * eye->v.y)
    - ((2.0 * eye->pos.z * eye->v.z) / tan_square);
  c =  (pow(eye->pos.x, 2.0))
    + (pow(eye->pos.y, 2.0))
    - (pow(eye->pos.z, 2.0) / tan_square);
  delta = pow(b, 2.0) - (4.0 * a * c);
  k = solve_eq(a, b, delta);
  p = eq_parametric(eye->pos, eye->v, k);
  if (double_are_same(check_limit(p, o), -1.0))
    return (-1.0);
  return (k);
}
