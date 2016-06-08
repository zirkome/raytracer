/*
** infos_objects.c for infos_objectsc in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Sun Jun  2 16:49:01 2013 nicolas bridoux
** Last update Sun Jun  9 16:33:54 2013 nicolas bridoux
*/

#include "parsing.h"
#include "utils.h"

void	fill_second_size(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "size2=\"", 7))
      obj->second_size = strtol(&file[*i + 7], NULL, 10);
  if (obj->second_size <= 0)
    obj->second_size = 50;
}

void	fill_checkerboard(char *file, int *i, t_obj *obj)
{
  obj->checkerboard = TRUE;
  while (END_BALISE)
    {
      if (!my_strncmp(&file[*i], "size=\"", 6))
	obj->checkerboard_size = strtol(&file[*i + 6], NULL, 10);
      if (!my_strncmp(&file[*i], "color=\"", 7))
	obj->checkerboard_color = strtol(&file[*i + 7], NULL, 16);
    }
  if (obj->checkerboard_size < 0)
    obj->checkerboard_size = ABS(obj->checkerboard_size);
}

void	fill_texture(char *file, int *i, t_obj *obj)
{
  int	k;
  char	tmp;

  while (END_BALISE)
    if (!my_strncmp(&file[*i], "texture=\"", 9))
      {
	k = *i + 9;
	while (file[++k] && file[k] != '"');
	tmp = file[k];
	file[k] = '\0';
	obj->texture.name = my_strdup(&file[*i + 9]);
	file[k] = tmp;
      }
}

void	fill_bump_map(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    {
      if (!my_strncmp(&file[*i], "x=\"", 3))
	obj->normal_perturb.x = strtod(&file[*i + 3], NULL);
      if (!my_strncmp(&file[*i], "y=\"", 3))
	obj->normal_perturb.y = strtod(&file[*i + 3], NULL);
      if (!my_strncmp(&file[*i], "z=\"", 3))
	obj->normal_perturb.z = strtod(&file[*i + 3], NULL);
    }
}
