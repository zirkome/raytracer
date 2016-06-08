/*
** cylinder.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 01:48:36 2013 guillaume fillon
** Last update Sun Jun  9 16:16:03 2013 freddy sallaberry
*/

#include "object.h"
#include "raytracer.h"
#include "utils.h"

t_vector	normal_cylinder(UNUSED t_cam *eye,
				UNUSED t_obj *obj, t_vector p)
{
  return (new_vector(p.x, p.y, 0.0));
}

double		inter_cylinder(t_cam *eye, t_obj *o)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	k;
  t_vector	p;

  a = pow(eye->v.x, 2.0) + pow(eye->v.y, 2.0);
  b = 2.0 * ((eye->v.x * eye->pos.x) + (eye->v.y * eye->pos.y));
  c = pow(eye->pos.x, 2.0)
    + pow(eye->pos.y, 2.0)
    - pow(o->size, 2.0);
  delta = pow(b, 2.0) - (4.0 * a * c);
  k = solve_eq(a, b, delta);
  p = eq_parametric(eye->pos, eye->v, k);
  if (double_are_same(check_limit(p, o), -1.0))
    return (-1.0);
  return (k);
}
