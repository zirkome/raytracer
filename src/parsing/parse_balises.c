/*
** parse_balises.c for parse_balises.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 15:31:31 2013 nicolas bridoux
** Last update Sun Jun  9 16:04:34 2013 guillaume fillon
*/

#include "parsing.h"
#include "utils.h"

void	fill_rot(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    {
      if (!my_strncmp(&file[*i], "x=\"", 3))
	obj->rot.x = strtol(&file[*i + 3], NULL, 10);
      if (!my_strncmp(&file[*i], "y=\"", 3))
	obj->rot.y = strtol(&file[*i + 3], NULL, 10);
      if (!my_strncmp(&file[*i], "z=\"", 3))
	obj->rot.z = strtol(&file[*i + 3], NULL, 10);
    }
}

void	fill_pos(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    {
      if (!my_strncmp(&file[*i], "x=\"", 3))
	obj->trans.x = strtol(&file[*i + 3], NULL, 10);
      if (!my_strncmp(&file[*i], "y=\"", 3))
	obj->trans.y = strtol(&file[*i + 3], NULL, 10);
      if (!my_strncmp(&file[*i], "z=\"", 3))
	obj->trans.z = strtol(&file[*i + 3], NULL, 10);
    }
}

void	fill_color(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "color=\"", 7))
      obj->color = int_to_rgb(strtoul(&file[*i + 7], NULL, 16));
}

void	fill_size(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "size=\"", 6))
      obj->size = strtod(&file[*i + 6], NULL);
  if (obj->size <= 0)
    obj->size = 150;
}

void	fill_shiny(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    if (!my_strncmp(&file[*i], "shiny=\"", 7))
      obj->shiny = strtod(&file[*i + 7], NULL);
}
