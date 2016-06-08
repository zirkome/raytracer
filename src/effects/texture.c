/*
** texture.c for texture.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Sat Jun  1 12:40:53 2013 nicolas bridoux
** Last update Sun Jun  9 13:09:17 2013 nicolas bridoux
*/

#include "raytracer.h"
#include "bmp.h"

int		get_color_img(unsigned char *img, int x, int y, int width)
{
  int		color;
  int		pos;

  color = 0;
  if (!img)
    return (BLACK);
  pos = (y * width * 3) + (x * 3);
  color |= img[pos];
  color <<= 8;
  color |= img[pos + 1];
  color <<= 8;
  color |= img[pos + 2];
  return (color);
}

void		load_texture(t_obj **tab)
{
  int		i;
  t_bmp_header	hdr;

  i = -1;
  while (tab[++i])
    if (tab[i]->texture.name)
      {
	tab[i]->texture.img = load_bmp(tab[i]->texture.name, &hdr, -1);
	tab[i]->texture.width = hdr.width;
	tab[i]->texture.height = hdr.height;
      }
}

t_color		apply_texture(t_rt *scene, t_obj *obj, double k)
{
  t_vector	p;
  t_vector	n;
  double	x;
  double	y;
  uint		color;

  if (!obj->texture.img)
    return (obj->color);
  p = eq_parametric(scene->eye->pos, scene->eye->v, k);
  n = obj->normal(scene->eye, obj, p);
  n = translate_vector(n, obj->trans, -1);
  n = rotate_vector(n, obj->rot, -1);
  n = normalize(n);
  x = 1.0 + atan2(n.x, n.y) / M_PI;
  y = 0.5 - 2.0 * (asin(n.z) / (2 * M_PI));
  x *= obj->texture.width;
  y *= obj->texture.height;
  color = get_color_img(obj->texture.img, x, y, obj->texture.width);
  return (int_to_rgb(color));
}
