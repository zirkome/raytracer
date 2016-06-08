/*
** fill_infos_obj.c for get_objects.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 15:11:24 2013 nicolas bridoux
** Last update Sun Jun  9 16:34:02 2013 nicolas bridoux
*/

#include "parsing.h"
#include "utils.h"

static t_pars	g_tab[] =
  {
    {"<rotate ", &fill_rot},
    {"<pos ", &fill_pos},
    {"<color ", &fill_color},
    {"<size ", &fill_size},
    {"<size2 ", &fill_second_size},
    {"<shiny ", &fill_shiny},
    {"<diffuse ", &fill_diffuse},
    {"<specular ", &fill_specular},
    {"<perlin ", &fill_perlin},
    {"<texture ", &fill_texture},
    {"<bumpmap ", &fill_bump_map},
    {"<checkerboard ", &fill_checkerboard},
    {"<limit ", &fill_limit},
    {NULL, NULL}
  };

void	fill_infos_obj(char *file, int *i, t_obj *obj)
{
  int	k;

  k = -1;
  while (g_tab[++k].name)
    if (!my_strncmp(&file[*i], g_tab[k].name, my_strlen(g_tab[k].name)))
      g_tab[k].func(file, i, obj);
}

void	fill_diffuse(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "diffuse=\"", 9))
      obj->diffuse = strtod(&file[*i + 9], NULL);
}

void	fill_color_perlin(char *file, int *i, t_obj *obj)
{
  if (!my_strncmp(&file[*i], "color1=\"", 8))
    obj->perlin.color_one = strtol(&file[*i + 8], NULL, 16);
  if (!my_strncmp(&file[*i], "color2=\"", 8))
    obj->perlin.color_two = strtol(&file[*i + 8], NULL, 16);
  if (!my_strncmp(&file[*i], "color3=\"", 8))
    obj->perlin.color_tree = strtol(&file[*i + 8], NULL, 16);
}

void	fill_perlin(char *file, int *i, t_obj *obj)
{
  obj->perlin.type = 1;
  while (END_BALISE)
    {
      fill_color_perlin(file, i, obj);
      if (!my_strncmp(&file[*i], "pers=\"", 6))
	obj->perlin.pers = strtod(&file[*i + 6], NULL);
      if (!my_strncmp(&file[*i], "coef=\"", 6))
	obj->perlin.coef = strtod(&file[*i + 6], NULL);
      if (!my_strncmp(&file[*i], "type=\"", 6))
	obj->perlin.type = (strtol(&file[*i + 6], NULL, 10) % 2) + 1;
    }
}

void	fill_specular(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "specular=\"", 10))
      obj->specular = strtod(&file[*i + 10], NULL);
}
