/*
** perlin_noise.c for perlin_noise.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 18:57:10 2013 nicolas bridoux
** Last update Sun Jun  9 16:20:40 2013 guillaume fillon
*/

#include "raytracer.h"

static t_color		get_color(int color)
{
  t_color		ret;

  ret.r = color >> 16;
  ret.g = (color >> 8) & 0xFF;
  ret.b = color & 0xFF;
  ret.r /= 255;
  ret.g /= 255;
  ret.b /= 255;
  return (ret);
}

static int	build_color(double red, double green, double blue)
{
  int		color;

  color = (int)(ABS(red) * 255);
  color <<= 8;
  color += (int)(ABS(green) * 255);
  color <<= 8;
  color += (int)(ABS(blue) * 255);
  return (color);
}

static int		get_limen_color(double value, t_color one,
					t_color two, t_color tree)
{
  double		f;
  t_color		result;

  if (value <= S1)
    result = one;
  else if (value < S2)
    {
      f = (value - S1) / (S2 -S1);
      result.r = one.r * (1 - f) + two.r * f;
      result.g = one.g * (1 - f) + two.g * f;
      result.b = one.b * (1 - f) + two.b * f;
    }
  else if (value < S3)
    {
      f = (value - S2) / (S3 - S2);
      result.r = two.r * (1 - f) + tree.r * f;
      result.g = two.g * (1 - f) + tree.g * f;
      result.b = two.b * (1 - f) + tree.b * f;
    }
  else
    result = tree;
  return (build_color(result.r, result.g, result.b));
}

t_color		apply_perlin(int x, int y, t_obj *obj)
{
  double	value;
  static int	i = 0;

  if (!i++)
    fill_random_tab();
  value = perlin_noise(x, y, obj->perlin);
  if (obj->perlin.type == CURV)
    value = (1 - cos(20 * M_PI * ((double)x
				/ MAX_X + obj->perlin.coef * value))) / 2;
  else
     value = 1.0 - sqrt(fabs(sin(obj->perlin.coef * 10 * M_PI * value)));
  return (int_to_rgb(get_limen_color(value, get_color(obj->perlin.color_one),
				     get_color(obj->perlin.color_two),
				     get_color(obj->perlin.color_tree))));
}
