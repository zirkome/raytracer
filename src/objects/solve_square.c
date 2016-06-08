/*
** solve_square.c for solve_square.c in /home/bridou_n/Raytracer/new/src/objects
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jun  5 03:04:31 2013 nicolas bridoux
** Last update Sun Jun  9 16:26:47 2013 nicolas bridoux
*/

#include <math.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"

static int	solve_square(double *var, double *results)
{
  if (var[3] < 0.0)
    return (0);
  else if (abs(var[3]) < 1.0e-16)
    {
      results[0] = results[1] = 0.5 * var[1] / var[0];
      return 1;
    }
  var[3] = sqrt(var[3]);
  var[4] = 0.5 / var[0];
  if (var[4] > 0.0)
    {
      results[0] = (var[1] - var[3]) * var[4];
      results[1] = (var[1] + var[3]) * var[4];
    }
  else
    {
      results[0] = (var[1] + var[3]) * var[4];
      results[1] = (var[1] - var[3]) * var[4];
    }
  return (2);
}

int		solve_quadratic(t_sol obj, double *results)
{
  double	var[5];

  var[0] = obj.coef[2];
  var[1] = -obj.coef[1];
  var[2] = obj.coef[0];
  if (double_are_same(var[0], 0.0))
    {
      if (double_are_same(var[1], 0.0))
	return (0);
      results[0] = results[1] = var[2] / var[1];
      return (1);
    }
  var[3] = var[1] * var[1] - 4.0 * var[0] * var[2];
  return (solve_square(var, results));
}
