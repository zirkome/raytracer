/*
** translation.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 02:36:38 2013 guillaume fillon
** Last update Thu May 30 16:28:12 2013 guillaume fillon
*/

#include "raytracer.h"

t_vector	rotate_x(t_vector vec, double angle)
{
  double	tmp_x;
  double	tmp_y;
  double	tmp_z;

  angle = RADIAN(angle);
  tmp_x = vec.x;
  tmp_y = (vec.y * cos(angle)) - (vec.z * sin(angle));
  tmp_z = (vec.y * sin(angle)) + (vec.z * cos(angle));
  vec.x = tmp_x;
  vec.y = tmp_y;
  vec.z = tmp_z;
  return (vec);
}

t_vector	rotate_y(t_vector vec, double angle)
{
  double	tmp_x;
  double	tmp_y;
  double	tmp_z;

  angle = RADIAN(angle);
  tmp_x = (vec.z * sin(angle)) + (vec.x * cos(angle));
  tmp_y = vec.y;
  tmp_z = (-vec.x * sin(angle)) + (vec.z * cos(angle));
  vec.x = tmp_x;
  vec.y = tmp_y;
  vec.z = tmp_z;
  return (vec);
}

t_vector	rotate_z(t_vector vec, double angle)
{
  double	tmp_x;
  double	tmp_y;
  double	tmp_z;

  angle = RADIAN(angle);
  tmp_x = (vec.x * cos(angle)) - (vec.y * sin(angle));
  tmp_y = (vec.x * sin(angle)) + (vec.y * cos(angle));
  tmp_z = vec.z;
  vec.x = tmp_x;
  vec.y = tmp_y;
  vec.z = tmp_z;
  return (vec);
}
