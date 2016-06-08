/*
** solve_cubic.c for solve_cubic.c in /home/bridou_n/Raytracer/new/src/objects
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jun  5 03:10:08 2013 nicolas bridoux
** Last update Sun Jun  9 16:28:02 2013 nicolas bridoux
*/

#include <math.h>
#include "raytracer.h"
#include "object.h"
#include "utils.h"

static int	solve_exp_tree(double *var, double *results)
{
  var[8] = var[9] * var[9];
  var[0] = (var[8] - 3.0 * var[10]) / 9.0;
  var[1] = (var[9] * (var[8] - 4.5 * var[10]) + 13.5 * var[11]) / 27.0;
  var[2] = var[0] * var[0] * var[0];
  var[3] = var[1] * var[1];
  var[5] = var[2] - var[3];
  var[6] = var[9] / 3.0;
  if (var[5] >= 0.0)
    {
      var[5] = var[1] / sqrt (var[2]);
      var[7] = acos (var[5]) / 3.0;
      var[4] = -2.0 * sqrt(var[0]);
      results[0] = var[4] * cos(var[7]) - var[6];
      results[1] = var[4] * cos(var[7] + TWO_PI_3) - var[6];
      results[2] = var[4] * cos(var[7] + FOUR_PI_3) - var[6];
      return (3);
    }
  else
    {
      var[4] = pow(sqrt(var[3] - var[2]) + fabs(var[1]), 1.0 / 3.0);
      results[0] = (var[1] < 0) ? ((var[4] + var[0] / var[4]) - var[6])
	: (-(var[4] + var[0] / var[4]) - var[6]);
      return (TRUE);
    }
}

int		solve_cubic(t_sol obj, double *results)
{
  double	var[13];

  var[12] = obj.coef[3];
  if (fabs(var[12]) < EPSILON)
    return (solve_quadratic(obj, results));
  else
    {
      if (!double_are_same(var[12], 1.0))
	{
	  var[9] = obj.coef[2] / var[12];
	  var[10] = obj.coef[1] / var[12];
	  var[11] = obj.coef[0] / var[12];
	}
      else
	{
	  var[9] = obj.coef[2];
	  var[10] = obj.coef[1];
	  var[11] = obj.coef[0];
	}
    }
  return (solve_exp_tree(var, results));
}
