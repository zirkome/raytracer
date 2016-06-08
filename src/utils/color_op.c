/*
** color_op.c for RT in /home/fillon_g/projects/raytracer-2017-bridou_n/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Jun  4 17:45:31 2013 guillaume fillon
** Last update Sun Jun  9 14:17:24 2013 guillaume fillon
*/

#include "color.h"

t_color		color_add(t_color c1, t_color c2)
{
  c1.r = c1.r + c2.r;
  c1.g = c1.g + c2.g;
  c1.b = c1.b + c2.b;
  return (c1);
}

t_color		color_add2(t_color c1, t_color c2)
{
  c1.r = ABS_COLOR(c1.r + c2.r);
  c1.g = ABS_COLOR(c1.g + c2.g);
  c1.b = ABS_COLOR(c1.b + c2.b);
  return (c1);
}

t_color		color_mult(t_color c1, t_color c2)
{
  c1.r = c1.r * c2.r;
  c1.g = c1.g * c2.g;
  c1.b = c1.b * c2.b;
  return (c1);
}

t_color		color_scale(t_color c1, double k)
{
  c1.r = c1.r * k;
  c1.g = c1.g * k;
  c1.b = c1.b * k;
  return (c1);
}

t_color		new_color(double r, double g, double b)
{
  t_color	c;

  c.r = r;
  c.b = b;
  c.g = g;
  return (c);
}
