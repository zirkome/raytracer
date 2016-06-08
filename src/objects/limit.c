/*
** limit.c for limit in /home/sallab_f/co_svn/raytracer-2017-bridou_n/src/objects
**
** Made by freddy sallaberry
** Login   <sallab_f@epitech.net>
** 
** Started on  Sun Jun  9 13:54:32 2013 freddy sallaberry
** Last update Sun Jun  9 17:44:46 2013 freddy sallaberry
*/

#include "raytracer.h"
#include "utils.h"

int		compare_limit(t_vector lmax, t_vector lmin, char coord)
{
  if (coord == 'x')
    {
      if (double_are_same(lmax.x, lmin.x))
	return (FALSE);
    }
  if (coord == 'y')
    {
      if (double_are_same(lmax.y, lmin.y))
	return (FALSE);
    }
  if (coord == 'z')
    {
      if (double_are_same(lmax.z, lmin.z))
	return (FALSE);
    }
  return (TRUE);
}

double		check_limit(t_vector p, t_obj *o)
{
  if (o->limit == TRUE)
    {
      if (compare_limit(o->limit_max, o->limit_min, 'x') &&
	  (p.x > o->limit_max.x || p.x < o->limit_min.x))
        return (-1.0);
      if (compare_limit(o->limit_max, o->limit_min, 'y') &&
	  (p.y > o->limit_max.y || p.y < o->limit_min.y))
        return (-1.0);
      if (compare_limit(o->limit_max, o->limit_min, 'z') &&
	  (p.z > o->limit_max.z || p.z < o->limit_min.z))
        return (-1.0);
    }
  return (0.0);
}
