/*
** movements.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 13:43:54 2013 guillaume fillon
** Last update Sun Jun  9 15:48:38 2013 guillaume fillon
*/

#include "raytracer.h"
#include "vector.h"

t_vector	rotate_vector(t_vector vec, t_vector rot, int j)
{
  if (j == -1)
    {
      vec = rotate_z(vec, j * rot.z);
      vec = rotate_y(vec, j * rot.y);
      vec = rotate_x(vec, j * rot.x);
    }
  else
    {
      vec = rotate_x(vec, j * rot.x);
      vec = rotate_y(vec, j * rot.y);
      vec = rotate_z(vec, j * rot.z);
    }
  return (vec);
}

t_vector	translate_vector(t_vector vec, t_vector trans, int j)
{
  vec.x = vec.x + (j * trans.x);
  vec.y = vec.y + (j * trans.y);
  vec.z = vec.z + (j * trans.z);
  return (vec);
}

void		move_object(t_cam *eye, t_obj *obj, int j)
{
  if (j == -1)
    {
      eye->pos = translate_vector(eye->pos, obj->trans, j);
      eye->pos = rotate_vector(eye->pos, obj->rot, j);
      eye->v = rotate_vector(eye->v, obj->rot, j);
    }
  else
    {
      eye->pos = rotate_vector(eye->pos, obj->rot, j);
      eye->pos = translate_vector(eye->pos, obj->trans, j);
      eye->v = rotate_vector(eye->v, obj->rot, j);
    }
}
