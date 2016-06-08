/*
** contrast.c for raytracer in /home/collin_b//raytracer-2017-bridou_n/new/src
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Mon Jun  3 21:38:21 2013 jonathan collinet
** Last update Wed Jun  5 00:00:00 2013 jonathan collinet
*/

#include "raytracer.h"

t_color		get_contrast(uint color1, uint color2, t_color color)
{
  if (((color.r * 0.299) + (color.g * 0.587) + (color.b * 0.114)) < 125)
    return (int_to_rgb(color1));
  return (int_to_rgb(color2));
}
