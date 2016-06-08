/*
** plane.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 02:29:10 2013 guillaume fillon
** Last update Sun Jun  9 15:42:30 2013 guillaume fillon
*/

#include "raytracer.h"
#include "object.h"
#include "utils.h"

t_vector	normal_plane(t_cam *eye, UNUSED t_obj *obj, UNUSED t_vector p)
{
  if (eye->pos.z < obj->trans.z)
    return (new_vector(0.0, 0.0, -100.0));
  return (new_vector(0.0, 0.0, 100.0));
}

double		inter_plane(t_cam *eye, UNUSED t_obj *plane)
{
  if (double_are_same(eye->v.z, 0.0) || double_are_same(eye->pos.z, 0.0))
    return (-1.0);
  return (((-eye->pos.z / eye->v.z) < 0.0)
	  ? (-1.0) : (-eye->pos.z / eye->v.z));
}
