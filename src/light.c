/*
** light.c for raytracer in /home/collin_b//raytracer-2017-bridou_n/new
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Sun Jun  2 01:53:02 2013 jonathan collinet
** Last update Sun Jun  9 16:12:08 2013 guillaume fillon
*/

#include "raytracer.h"
#include "utils.h"
#include "vector.h"

t_color		find_max_color(t_spot **spots)
{
  int		i;
  t_color	color;

  i = -1;
  color = new_color(0.0, 0.0, 0.0);
  while (spots[++i])
    color = color_add(color, spots[i]->color_tmp);
  color.r /= i;
  color.g /= i;
  color.b /= i;
  return (color);
}

t_color		diffuse_light(double angle, t_obj *o, t_spot cspot)
{
  t_color	color;
  double	coef;

  color = new_color(0, 0, 0);
  if (double_are_same(o->color.r, 0.0) && double_are_same(o->color.g, 0.0) &&
      double_are_same(o->color.b, 0.0))
    return (color);
  coef = angle * o->diffuse * cspot.intensity;
  color.r = ABS_COLOR((o->color.r * coef) + (cspot.color.r * coef * o->shiny));
  color.g = ABS_COLOR((o->color.g * coef) + (cspot.color.g * coef * o->shiny));
  color.b = ABS_COLOR((o->color.b * coef) + (cspot.color.b * coef * o->shiny));
  return (color);
}

t_vector	calc_normal(t_cam *eye, t_obj *o, t_vector p)
{
  t_vector	n;

  p = translate_vector(p, o->trans, -1);
  p = rotate_vector(p, o->rot, -1);
  n = o->normal(eye, o, p);
  n = rotate_vector(n, o->rot, 1);
  if (!double_are_same(o->normal_perturb.x, 0.0)
      || !double_are_same(o->normal_perturb.y, 0.0)
      || !double_are_same(o->normal_perturb.z, 0.0))
    n = waves(n, o->normal_perturb, p);
  return (n);
}

t_color		specular_light(t_obj *o, t_spot spt, t_rt *scene, t_vector v[])
{
  double	spec;
  t_vector	r;
  t_color	color;

  color = new_color(0, 0, 0);
  r = vec_reflective(v[1], v[2]);
  spec = dot_product(scene->eye->v, r);
  if (spec > EPSILON)
    {
      spec = pow(spec, 40) * o->specular * spt.intensity;
      color = color_scale(new_color(0xFF, 0xFF, 0xFF), spec);
    }
  return (color);
}

t_color		phong_light(t_spot cspot, t_obj *o, t_rt *scene, double k)
{
  double	a;
  t_color	amb;
  t_color	diff;
  t_color	spec;
  t_vector	vec[4];

  vec[0] = eq_parametric(scene->eye->pos, scene->eye->v, k);
  vec[1] = sub_vector(cspot.pos, vec[0]);
  vec[2] = calc_normal(scene->eye, o, vec[0]);
  vec[3] = scene->eye->v;
  a = get_angle(vec[1], vec[2]);
  amb = color_scale(o->color, scene->amb);
  diff = new_color(0, 0, 0);
  spec = new_color(0, 0, 0);
  if (a > EPSILON)
    diff = diffuse_light(a, o, cspot);
  if (o->specular > EPSILON)
    spec = specular_light(o, cspot, scene, vec);
  return (color_add2(color_add2(amb, diff), spec));
}
