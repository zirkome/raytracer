/*
** antialiasing.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-2017-bridou_n/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  2 02:03:53 2013 guillaume fillon
** Last update Sun Jun  9 15:56:11 2013 guillaume fillon
*/

#include "raytracer.h"

static uint	average(uint *color, size_t size)
{
  t_color	final;
  t_color	tmp;
  int		i;

  i = 0;
  final = int_to_rgb(0x000000);
  while (i < (int)size)
    {
      tmp = int_to_rgb(color[i]);
      final.r += tmp.r;
      final.g += tmp.g;
      final.b += tmp.b;
      ++i;
    }
  final.r /= size;
  final.g /= size;
  final.b /= size;
  return (rgb_to_int(final));
}

uint		msaa(int i, int j, t_rt *s)
{
  uint		*color;
  uint		k;
  uint		l;

  k = 0;
  l = 0;
  color = malloc((s->antialiasing * s->antialiasing) * sizeof(int));
  while (k < (uint) (s->antialiasing * s->antialiasing))
    {
      if (k % s->antialiasing == 0)
	++l;
      color[k] = raytracer(s,
			   i + ((double)(k % s->antialiasing))
			   * (1.0/(double)s->antialiasing),
			   j + ((double)(l - 1)
				* (1.0/(double)s->antialiasing)));
      ++k;
    }
  return (average(color, s->antialiasing * s->antialiasing));
}
