/*
** spot.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 14:13:44 2013 guillaume fillon
** Last update Sun Jun  9 15:10:37 2013 guillaume fillon
*/

#include "raytracer.h"

t_spot		*new_spot(t_vector pos, t_color color, double intensity)
{
  t_spot	*spot;

  if ((spot = malloc(sizeof(*spot))) == NULL)
    return (NULL);
  spot->pos = pos;
  spot->color = color;
  spot->color_tmp = new_color(0, 0, 0);
  spot->intensity = intensity;
  return (spot);
}
