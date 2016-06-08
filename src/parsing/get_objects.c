/*
** get_objects.c for get_objects.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 14:49:16 2013 nicolas bridoux
** Last update Sun Jun  9 17:19:14 2013 freddy sallaberry
*/

#include "parsing.h"
#include "utils.h"

static t_type	g_type[] =
  {
    {"cone", &inter_cone, &normal_cone},
    {"cube", &inter_cube, &normal_cube},
    {"tore", &inter_tore, &normal_tore},
    {"cylinder", &inter_cylinder, &normal_cylinder},
    {"paraboloide", &inter_paraboloide, &normal_paraboloide},
    {"hyperboloide", &inter_hyperboloide, &normal_hyperboloide},
    {"plan", &inter_plane, &normal_plane},
    {"cone", &inter_cone, &normal_cone},
    {NULL, NULL, NULL}
  };

static int	nb_objs(char *file)
{
  int		i;
  int		count;

  count = 1;
  i = -1;
  while (file[++i])
    if (!my_strncmp(&file[i], "<object type=\"", 14))
      ++count;
  return (++count);
}

static void	complete_type(t_obj *obj, char *name)
{
  int		i;

  i = -1;
  while (g_type[++i].name)
    if (!my_strcmp(g_type[i].name, name))
      {
	obj->inter = g_type[i].inter;
	obj->normal = g_type[i].normal;
      }
  if (!obj->inter)
    {
      obj->inter = &inter_sphere;
      obj->normal = &normal_sphere;
    }
}

static void	init_end_obj(t_obj *obj)
{
  obj->texture.img = NULL;
  obj->texture.name = NULL;
  obj->texture.height = 0;
  obj->texture.width = 0;
  obj->normal_perturb = new_vector(0.0, 0.0, 0.0);
  obj->checkerboard = FALSE;
  obj->checkerboard_color = BLACK;
  obj->checkerboard_size = 50;
  obj->limit = FALSE;
  obj->limit_min = new_vector(0.0, 0.0, 0.0);
  obj->limit_max = new_vector(0.0, 0.0, 0.0);
}

static void	init_obj(t_obj *obj, char *name)
{
  int		i;

  i = -1;
  obj->inter = NULL;
  obj->normal = NULL;
  while (name[++i] && name[i] != '"');
  name[i] = '\0';
  complete_type(obj, name);
  name[i] = '"';
  obj->trans = new_vector(0.0, 0.0, 0.0);
  obj->rot = new_vector(0.0, 0.0, 0.0);
  obj->specular = 0.0;
  obj->shiny = 0.0;
  obj->color = new_color(0xFF, 0xCC, 0xFF);
  obj->size = 150.0;
  obj->second_size = 50;
  obj->diffuse = 1.0;
  obj->perlin.color_one = 0xCCCCCC;
  obj->perlin.color_two = 0x00CCCB;
  obj->perlin.color_tree = 0x2C75FF;
  obj->perlin.type = NOTHING;
  obj->perlin.coef = 0.5;
  obj->perlin.pers = 0.6;
  init_end_obj(obj);
}

t_obj		**get_objects(char *file)
{
  t_obj		**tab;
  int		i;
  int		k;

  if (!(tab = malloc(sizeof(t_obj *) * nb_objs(file))))
    my_error("Not enough memory\n", 1);
  i = -1;
  k = -1;
  while (file[++i])
    if (!my_strncmp(&file[i], "<object type=\"", 14))
      {
	if (!(tab[++k] = malloc(sizeof(t_obj))))
	  my_error("Not enough memory\n", 1);
	init_obj(tab[k], &file[i + 14]);
	while (file[++i] && my_strncmp(&file[i], "</object>", 9))
	  fill_infos_obj(file, &i, tab[k]);
      }
  tab[++k] = NULL;
  return ((!k) ? (NULL) : (tab));
}
