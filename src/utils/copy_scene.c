/*
** copy_scene.c for copy_scene.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Sat Jun  1 10:04:28 2013 nicolas bridoux
** Last update Sun Jun  9 16:38:16 2013 nicolas bridoux
*/

#include "utils.h"

static t_cam	*cpy_eye(t_cam *eye)
{
  t_cam		*cpy;

  if (!(cpy = malloc(sizeof(t_cam))))
    return (NULL);
  cpy->pos = eye->pos;
  cpy->rot = eye->rot;
  cpy->v = eye->v;
  return (cpy);
}

static t_spot	**cpy_spots(t_spot **spots)
{
  t_spot	**cpy;
  int		i;

  if (!(cpy = malloc(sizeof(t_spot *) * (len_tab((void **)spots) + 1))))
    return (NULL);
  i = -1;
  while (spots[++i])
    {
      if (!(cpy[i] = malloc(sizeof(t_spot))))
	return (NULL);
      cpy[i]->pos = spots[i]->pos;
      cpy[i]->color = spots[i]->color;
      cpy[i]->color_tmp = spots[i]->color_tmp;
      cpy[i]->intensity = spots[i]->intensity;
    }
  cpy[i] = NULL;
  return (cpy);
}

static void	cpy_obj_carac(t_obj *cpy, t_obj *src)
{
  cpy->rot = src->rot;
  cpy->trans = src->trans;
  cpy->perlin = src->perlin;
  cpy->specular = src->specular;
  cpy->diffuse = src->diffuse;
  cpy->size = src->size;
  cpy->second_size = src->second_size;
  cpy->shiny = src->shiny;
  cpy->color = src->color;
  cpy->normal = src->normal;
  cpy->inter = src->inter;
  cpy->texture = src->texture;
  cpy->normal_perturb = src->normal_perturb;
  cpy->checkerboard = src->checkerboard;
  cpy->checkerboard_size = src->checkerboard_size;
  cpy->checkerboard_color = src->checkerboard_color;
  cpy->limit = src->limit;
  cpy->limit_min = src->limit_min;
  cpy->limit_max = src->limit_max;
}

static t_obj	**cpy_objs(t_obj **objs)
{
  t_obj		**cpy;
  int		i;

  if (!(cpy = malloc(sizeof(t_obj *) * (len_tab((void **)objs) + 1))))
    return (NULL);
  i = -1;
  while (objs[++i])
    {
      if (!(cpy[i] = malloc(sizeof(t_obj))))
	return (NULL);
      cpy_obj_carac(cpy[i], objs[i]);
    }
  cpy[i] = NULL;
  return (cpy);
}

t_rt	copy_scene(t_rt *s)
{
  t_rt	cpy;

  cpy.mlx = s->mlx;
  cpy.start = s->start;
  cpy.end = s->end;
  cpy.amb = s->amb;
  if (!(cpy.eye = cpy_eye(s->eye)))
    exit(EXIT_FAILURE);
  cpy.header = s->header;
  if (!(cpy.objs = cpy_objs(s->objs)))
    exit(EXIT_FAILURE);
  if (!(cpy.spots = cpy_spots(s->spots)))
    exit(EXIT_FAILURE);
  cpy.antialiasing = s->antialiasing;
  cpy.filter_background = s->filter_background;
  cpy.filter_type = s->filter_type;
  cpy.filter_objects = s->filter_objects;
  cpy.contrast = s->contrast;
  cpy.contrast_color_one = s->contrast_color_one;
  cpy.contrast_color_two = s->contrast_color_two;
  cpy.gamma = s->gamma;
  return (cpy);
}
