/*
** apply_effects.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 16:59:49 2013 guillaume fillon
** Last update Sun Jun  9 15:51:34 2013 guillaume fillon
*/

#include "raytracer.h"

int		shaded(t_spot cur_spot, t_obj *o, t_rt *scene, double k)
{
  int		i;
  double	k1;
  t_cam		neye;

  neye.pos = eq_parametric(scene->eye->pos, scene->eye->v, k);
  neye.v = sub_vector(cur_spot.pos, neye.pos);
  i = 0;
  k1 = -1.0;
  while (scene->objs[i] != NULL)
    {
      if (scene->objs[i] != o)
      	{
	  move_object(&neye, scene->objs[i], -1);
	  k1 = scene->objs[i]->inter(&neye, scene->objs[i]);
	  move_object(&neye, scene->objs[i], 1);
	}
      if (k1 <= 1.0 - EPSILON && k1 > EPSILON)
	return (1);
      ++i;
    }
  return (0);
}

t_color		apply_light(t_rt *scene, t_obj *o, double k)
{
  int		i;

  i = 0;
  while (scene->spots[i])
    {
      if (shaded(*scene->spots[i], o, scene, k))
	scene->spots[i]->color_tmp = new_color(0, 0, 0);
      else
	scene->spots[i]->color_tmp =
	  phong_light(*scene->spots[i], o, scene, k);
      ++i;
    }
  return (find_max_color(scene->spots));
}

t_color		obj_effects(t_rt *scene, t_obj *o, t_vector pixel, double k)
{
  t_color	color;

  if (o == NULL)
    return (new_color(0x33, 0x33, 0x33));
  if (o->perlin.type != NOTHING)
    o->color = apply_perlin(pixel.x, pixel.y, o);
  if (o->inter == inter_sphere && o->texture.name)
    o->color = apply_texture(scene, o, k);
  if (o->checkerboard && checkerboard(o, scene, k))
    return (fade_checkerboard(scene, o, k));
  color = apply_light(scene, o, k);
  return (color);
}

uint		apply_effects(t_rt *scene, t_obj *o, t_vector pixel, double k)
{
  t_color	color;

  if (o != NULL)
    {
      color = obj_effects(scene, o, pixel, k);
      if (scene->filter_objects == TRUE)
      	color = add_filter(scene, color);
      if (scene->contrast)
	color = get_contrast(scene->contrast_color_one,
			     scene->contrast_color_two, color);
      return (rgb_to_int(gamma_correction(scene, color)));
    }
  color = new_color(0x33, 0x33, 0x33);
  if (scene->filter_background == TRUE)
    color = add_filter(scene, color);
  return (rgb_to_int(gamma_correction(scene, color)));
}
