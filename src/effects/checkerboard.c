/*
** checkerboard.c for checkerboard.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Tue Jun  4 15:24:19 2013 nicolas bridoux
** Last update Sat Jun  8 22:35:05 2013 jonathan collinet
*/

#include "raytracer.h"

t_color		fade_checkerboard(t_rt *scene, t_obj *o, double k)
{
  t_color	tmp;
  t_color	color_tmp;

  tmp = o->color;
  color_tmp = fade_rgb(int_to_rgb(o->checkerboard_color), o->color);
  o->color = color_tmp;
  color_tmp = apply_light(scene, o, k);
  o->color = tmp;
  return (color_tmp);
}

uint		checkerboard(t_obj *obj, t_rt *scene, double k)
{
  t_vector	p;
  int		size;
  double	val;

  size = obj->checkerboard_size;
  p = eq_parametric(scene->eye->pos, scene->eye->v, k);
  val = cos((M_PI / size) * p.y) * cos((M_PI / size) * p.z);
  if (obj->inter == inter_plane)
    val *= cos((M_PI / size) * p.x);
  return ((val >= 0) ? (TRUE) : (FALSE));
}
