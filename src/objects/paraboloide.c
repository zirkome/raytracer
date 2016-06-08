/*
** paraboloide.c for paraboloide in /home/sallab_f/co_svn/raytracer-2017-bridou_n/new/src/objects
**
** Made by freddy sallaberry
** Login   <sallab_f@epitech.net>
**
** Started on  Tue Jun  4 12:20:49 2013 freddy sallaberry
** Last update Sun Jun  9 16:16:28 2013 freddy sallaberry
*/

#include "raytracer.h"
#include "object.h"
#include "utils.h"

t_vector	normal_paraboloide(UNUSED t_cam *eye,
				   UNUSED t_obj *obj, t_vector p)
{
  return (new_vector(p.x, p.y, -0.6));
}

double		inter_paraboloide(t_cam *eye, t_obj *o)
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
    + pow(eye->v.y, 2.0);
  b = 2 * (eye->pos.x * eye->v.x
	   + eye->pos.y * eye->v.y)
    - tan_square * eye->v.z;
  c = pow(eye->pos.x, 2.0)
    + pow(eye->pos.y, 2.0)
    - tan_square * eye->pos.z;
  delta = pow(b, 2.0) - (4.0 * a * c);
  k = solve_eq(a, b, delta);
  p = eq_parametric(eye->pos, eye->v, k);
  if (double_are_same(check_limit(p, o), -1.0))
    return (-1.0);
  return (k);
}
