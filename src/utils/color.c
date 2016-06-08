/*
** color.c for raytracer in /home/collin_b//rererererere
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Thu May 30 14:08:11 2013 jonathan collinet
** Last update Sun Jun  9 14:17:18 2013 guillaume fillon
*/

#include "color.h"

t_color		fade_rgb(t_color color1, t_color color2)
{
  t_color	new;

  new.r = (color1.r + color2.r) / 2.0;
  new.g = (color1.g + color2.g) / 2.0;
  new.b = (color1.b + color2.b) / 2.0;
  return (new);
}

double		avg_rgb(t_color color)
{
  return ((color.r + color.g + color.b) / 3);
}

t_color		int_to_rgb(uint color)
{
  t_color	col;

  col.r = 0;
  col.r = ABS_COLOR(color >> 16);
  col.g = 0;
  col.g = ABS_COLOR((color >> 8) & 0xFF);
  col.b = 0;
  col.b = ABS_COLOR(color & 0xFF);
  return (col);
}

uint		rgb_to_int(t_color c)
{
  uint		col;

  col = 0;
  col <<= 8;
  col |= (unsigned char)c.r;
  col <<= 8;
  col |= (unsigned char)c.g;
  col <<= 8;
  col |= (unsigned char)c.b;
  return (col);
}
