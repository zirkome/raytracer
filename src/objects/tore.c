/*
** tore.c for tore.c in /home/bridou_n/test/RayTracer brugevin-roger/RayTracer/Synthese/objets
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jun  5 01:18:57 2013 nicolas bridoux
** Last update Sun Jun  9 15:23:31 2013 guillaume fillon
*/

#include "raytracer.h"
#include "object.h"

double		find_min_root(int nb_roots, double *roots)
{
  int		i;
  double	k;

  i = -1;
  if (!nb_roots)
    return (0.0);
  else
    {
      k = roots[0];
      while (++i < nb_roots)
	if (roots[i] > 0.0 && roots[i] < k)
	  k = roots[i];
      return (k);
    }
}

static void	init_obj(t_sol *obj, double *roots, double *var)
{
  obj->coef[0] = var[11];
  obj->coef[1] = var[10];
  obj->coef[2] = var[9];
  obj->coef[3] = var[8];
  obj->coef[4] = var[7];
  obj->n = 4;
  roots[0] = 0.0;
  roots[1] = 0.0;
  roots[2] = 0.0;
  roots[3] = 0.0;
}

double		inter_tore(t_cam *eye, t_obj *o)
{
  double	var[11];
  t_sol		obj;
  int		nb_roots;
  double	roots[4];

  var[1] = eye->v.x * eye->v.x + eye->v.y
    * eye->v.y + eye->v.z * eye->v.z;
  var[2] = 2.0 * (eye->v.x * eye->pos.x + eye->v.y
		       * eye->pos.y + eye->v.z * eye->pos.z);
  var[3] = eye->pos.x * eye->pos.x + eye->pos.y * eye->pos.y
    + eye->pos.z * eye->pos.z + o->size
    * o->size - o->second_size * o->second_size;
  var[0] = 4.0 * o->size * o->size;
  var[4] = var[0] * (eye->v.x * eye->v.x + eye->v.z * eye->v.z);
  var[5] = var[0] * 2 * (eye->v.x * eye->pos.x + eye->v.z * eye->pos.z);
  var[6] = var[0] * (eye->pos.x * eye->pos.x + eye->pos.z * eye->pos.z);
  var[7] = var[1] * var[1];
  var[8] = 2.0 * var[1] * var[2];
  var[9] = 2.0 * var[1] * var[3] + var[2] * var[2] - var[4];
  var[10] = 2.0 * var[2] * var[3] - var[5];
  var[11] = var[3] * var[3] - var[6];
  init_obj(&obj, roots, var);
  nb_roots = solve_quartic(obj, roots);
  return (find_min_root(nb_roots, roots));
}

t_vector	normal_tore(UNUSED t_cam *eye, t_obj *obj, t_vector p)
{
  t_vector	n;
  double	coef;

  coef = 4 * (p.x * p.x + p.y * p.y + p.z * p.z + obj->size * obj->size
	      - obj->second_size * obj->second_size);
  n.x = (p.x * coef - 8.0 * obj->size * obj->size * p.x);
  n.y = (p.y * coef);
  n.z = (p.z * coef - 8.0 * obj->size * obj->size * p.z);
  return (n);
}
