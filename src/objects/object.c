/*
** object.c<2> for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 01:32:27 2013 guillaume fillon
** Last update Sun Jun  9 15:44:03 2013 guillaume fillon
*/

#include "object.h"
#include "utils.h"

double		solve_eq(double a, double b, double delta)
{
  double	k1;
  double	k2;

  if (delta < 0.0)
    return (0.0);
  if (double_are_same(delta, 0.0))
    return ((-(b)) / (2.0 * a));
  k1 = (-(b) - sqrt(delta)) / (2.0 * a);
  k2 = (-(b) + sqrt(delta)) / (2.0 * a);
  return (MIN(k1, k2));
}

t_obj	*new_object(double size, t_vector trans, t_vector rot)
{
  t_obj	*obj;

  if ((obj = malloc(sizeof(*obj))) == NULL)
    return (NULL);
  obj->size = size;
  obj->trans = trans;
  obj->rot = rot;
  obj->color = new_color(255, 255, 255);
  obj->inter = NULL;
  return (obj);
}
