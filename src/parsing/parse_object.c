/*
** parse_object.c for parse_object.c in /home/bridou_n/Raytracer/src/parsing
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Sat Jun  8 16:43:55 2013 nicolas bridoux
** Last update Sun Jun  9 17:15:41 2013 freddy sallaberry
*/

#include "parsing.h"
#include "object.h"
#include "utils.h"

void	fill_limit(char *file, int *i, t_obj *obj)
{
  while (END_BALISE)
    {
      obj->limit = TRUE;
      if (!my_strncmp(&file[*i], "max_x=\"", 7))
	obj->limit_max.x = strtol(&file[*i + 7], NULL, 10);
      if (!my_strncmp(&file[*i], "max_y=\"", 7))
	obj->limit_max.y = strtol(&file[*i + 7], NULL, 10);
      if (!my_strncmp(&file[*i], "max_z=\"", 7))
	obj->limit_max.z = strtol(&file[*i + 7], NULL, 10);
      if (!my_strncmp(&file[*i], "min_x=\"", 7))
	obj->limit_min.x = strtol(&file[*i + 7], NULL, 10);
      if (!my_strncmp(&file[*i], "min_y=\"", 7))
	obj->limit_min.y = strtol(&file[*i + 7], NULL, 10);
      if (!my_strncmp(&file[*i], "min_z=\"", 7))
	obj->limit_min.z = strtol(&file[*i + 7], NULL, 10);
    }
}
