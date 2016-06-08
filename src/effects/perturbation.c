/*
** perturbation.c for raytracer in /home/collin_b//raytracer-2017-bridou_n/new
**
** Made by jonathan collinet
** Login   <collin_b@epitech.net>
**
** Started on  Sun Jun  2 01:55:07 2013 jonathan collinet
** Last update Sun Jun  9 15:54:43 2013 guillaume fillon
*/

#include "raytracer.h"
#include "utils.h"

static double	calc_wave(t_vector n, double cur_n,
			  double normal_perturb, double cur_p)
{
  return (cur_n + (cos(cur_p / normal_perturb)
		   * (get_norm(n) / normal_perturb)));
}

t_vector	waves(t_vector n, t_vector normal_perturb, t_vector p)
{
  t_vector	tmp;

  tmp = new_vector(n.x, n.y, n.z);
  if (!double_are_same(normal_perturb.x, 0.0))
    tmp.x = calc_wave(n, n.x, normal_perturb.x, p.x);
  if (!double_are_same(normal_perturb.y, 0.0))
    tmp.y = calc_wave(n, n.y, normal_perturb.y, p.y);
  if (!double_are_same(normal_perturb.z, 0.0))
    tmp.z = calc_wave(n, n.z, normal_perturb.z, p.z);
  if (!double_are_same(n.x, tmp.x))
    n.x = tmp.x;
  if (!double_are_same(n.y, tmp.y))
    n.y = tmp.y;
  if (!double_are_same(n.z, tmp.z))
    n.z = tmp.z;
  return (n);
}
