/*
** cube.c for cube.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jun  5 13:14:04 2013 nicolas bridoux
** Last update Sun Jun  9 15:23:42 2013 guillaume fillon
*/

#include "raytracer.h"
#include "object.h"

static void	init_obj(t_sol *obj, double *roots, double *var)
{
  obj->coef[0] = var[4];
  obj->coef[1] = var[3];
  obj->coef[2] = var[2];
  obj->coef[3] = var[1];
  obj->coef[4] = var[0];
  obj->n = 4;
  roots[0] = 0.0;
  roots[1] = 0.0;
  roots[2] = 0.0;
  roots[3] = 0.0;
}

static t_cam	apply_size(t_cam eye, t_obj *o)
{
  t_cam		new;

  new.v.x = eye.v.x /= o->size;
  new.v.y = eye.v.y /= o->size;
  new.v.z = eye.v.z /= o->size;
  new.pos.x = eye.pos.x /= o->size;
  new.pos.y = eye.pos.y /= o->size;
  new.pos.z = eye.pos.z /= o->size;
  return (new);
}

static void	fill_coefs(double *var, t_cam eye)
{
  var[0] += pow(eye.v.x, 4);
  var[1] += 4 * pow(eye.v.x, 3) * eye.pos.x;
  var[2] +=
    6 * eye.v.x * eye.v.x * eye.pos.x * eye.pos.x -
    5 * eye.v.x * eye.v.x;
  var[3] += 4 * eye.v.x * pow(eye.pos.x, 3) - 10 * eye.v.x * eye.pos.x;
  var[4] += pow(eye.pos.x, 4) - 5 * eye.pos.x * eye.pos.x;
  var[0] += pow(eye.v.y, 4);
  var[1] += 4 * pow(eye.v.y, 3) * eye.pos.y;
  var[2] +=
    6 * eye.v.y * eye.v.y * eye.pos.y * eye.pos.y -
    5 * eye.v.y * eye.v.y;
  var[3] += 4 * eye.v.y * pow(eye.pos.y, 3) - 10 * eye.v.y * eye.pos.y;
  var[4] += pow(eye.pos.y, 4) - 5 * eye.pos.y * eye.pos.y;
  var[0] += pow(eye.v.z, 4);
  var[1] += 4 * pow(eye.v.z, 3) * eye.pos.z;
  var[2] +=
    6 * eye.v.z * eye.v.z * eye.pos.z * eye.pos.z -
	5 * eye.v.z * eye.v.z;
  var[3] += 4 * eye.v.z * pow(eye.pos.z, 3) - 10 * eye.v.z * eye.pos.z;
  var[4] += pow(eye.pos.z, 4) - 5 * eye.pos.z * eye.pos.z;
}

double		inter_cube(t_cam *eye, UNUSED t_obj *o)
{
  double	roots[4];
  double	var[5];
  t_sol		obj;
  int		nb_roots;

  o->second_size = (int)o->second_size % 19;
  var[0] = 0.0;
  var[1] = 0.0;
  var[2] = 0.0;
  var[3] = 0.0;
  var[4] = o->second_size;
  fill_coefs(var, apply_size(*eye, o));
  init_obj(&obj, roots, var);
  nb_roots = solve_quartic(obj, roots);
  return (find_min_root(nb_roots, roots));
}

t_vector	normal_cube(UNUSED t_cam *eye, UNUSED t_obj *obj, t_vector p)
{
  t_vector	n;

  n.x = 4 * pow(p.x, 3.0) - 10 * p.x;
  n.y = 4 * pow(p.y, 3.0) - 10 * p.y;
  n.z = 4 * pow(p.z, 3.0) - 10 * p.z;
  return (n);
}
