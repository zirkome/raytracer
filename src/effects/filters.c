/*
** filters.c for raytracer in /home/collin_b//raytracer-2017-bridou_n/new
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Sun Jun  2 23:00:36 2013 jonathan collinet
** Last update Sun Jun  9 15:45:59 2013 guillaume fillon
*/

#include "raytracer.h"
#include "utils.h"

# define F_SEPIA	4
# define F_BW	        2
# define F_NEG		1

static t_color		filter_negative(t_color color)
{
  return (new_color(255 - color.r, 255 - color.g, 255 - color.b));
}

static t_color	filter_sepia(t_color color)
{
  t_color	new;
  double	sepia;

  sepia = avg_rgb(color);
  new.r = sepia / 2 + 127;
  new.g = sepia / 2 + 90;
  new.b = sepia / 2 + 15;
  return (new);
}

static t_color	filter_bw(t_color color)
{
  t_color	new;
  double	bw;

  bw = avg_rgb(color);
  new.r = bw;
  new.g = bw;
  new.b = bw;
  return (new);
}

t_color		add_filter(t_rt *s, t_color color)
{
  t_color	sepia;
  t_color	bw;

  sepia = color;
  bw = color;
  if (s->filter_type & F_SEPIA)
    sepia = filter_sepia(color);
  if (s->filter_type & F_BW)
    return ((bw = filter_bw(color)));
  else
    {
      color = fade_rgb(sepia, bw);
      if (s->filter_type & F_NEG)
	color = filter_negative(color);
      return (color);
    }
  color = fade_rgb(sepia, bw);
  if (s->filter_type & F_NEG)
    color = filter_negative(color);
  return (color);
}
