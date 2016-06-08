/*
** solveur.c for solveur.c in /home/bridou_n/Raytracer/new/src/objects
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jun  5 01:12:35 2013 nicolas bridoux
** Last update Sun Jun  9 16:23:31 2013 nicolas bridoux
*/

#include "object.h"
#include "utils.h"

static int	solve_second_part(double *var, double *results)
{
  int		i;

  i = 0;
  var[9] = var[12] * var[12];
  var[10] = -0.25 * var[1];
  var[7] = var[9] - 4.0 * (var[6] - var[13]);
  if (double_are_same(var[7], 0.0))
    results[i++] = -0.5 * var[12] - var[10];
  else if (var[7] > 0)
    {
      var[7] = sqrt(var[7]);
      results[i++] = -0.5 * (var[12] + var[7]) + var[10];
      results[i++] = -0.5 * (var[12] - var[7]) + var[10];
    }
  var[7] = var[9] - 4.0 * (var[6] + var[13]);
  if (double_are_same(var[7], 0.0))
    results[i++] = 0.5 * var[12] - var[10];
  else if (var[7] > 0)
    {
      var[7] = sqrt(var[7]);
      results[i++] = 0.5 * (var[12] + var[7]) + var[10];
      results[i++] = 0.5 * (var[12] - var[7]) + var[10];
    }
  return (i);

}

static int	solve_first_part(double *var, double *results)
{
  if (var[12] < 0.0)
    {
      if (var[12] > -EPSILON)
	var[12] = 0.0;
      else
	return (0);
    }
  if (var[12] < EPSILON)
    {
      var[13] = var[6] * var[6] - var[11];
      if (var[13] < 0.0)
	return (0);
      var[13] = sqrt(var[13]);
    }
  else
    {
      var[12] = sqrt(var[12]);
      var[13] = 0.5 * var[8] / var[12];
    }
  return (solve_second_part(var, results));
}

static int	test_solve_cubic(double *var, double *results, double *roots)
{
  t_sol		cubic;

  var[5] = var[1] * var[1];
  var[7] = -0.375 * var[5] + var[2];
  var[8] = 0.125 * var[5] * var[1] - 0.5 * var[1] * var[2] + var[3];
  var[11] = -0.01171875 * var[5] * var[5] + 0.0625 * var[5]
    * var[2] - 0.25 * var[1] * var[3] + var[4];
  cubic.coef[3] = 1.0;
  cubic.coef[2] = -0.5 * var[7];
  cubic.coef[1] = -var[11];
  cubic.coef[0] = 0.5 * var[11] * var[7] - 0.125 * var[8] * var[8];
  cubic.n = 3;
  if (solve_cubic(cubic, roots) > 0)
    var[6] = roots[0];
  else
    return (0);
  var[12] = 2.0 * var[6] - var[7];
  return (solve_first_part(var, results));
}

static void	fill_var_tab(double *var, t_sol obj)
{
  if (!double_are_same(var[0], 1.0))
    {
      var[1] = obj.coef[3] / var[0];
      var[2] = obj.coef[2] / var[0];
      var[3] = obj.coef[1] / var[0];
      var[4] = obj.coef[0] / var[0];
    }
  else
    {
      var[1] = obj.coef[3];
      var[2] = obj.coef[2];
      var[3] = obj.coef[1];
      var[4] = obj.coef[0];
    }
}

int		solve_quartic(t_sol obj, double *results)
{
  double	roots[3];
  double	var[14];
  t_sol		cubic;

  var[0] = obj.coef[4];
  if (fabs(var[0]) < 1.0e-16)
    return (solve_cubic(obj, results));
  if (fabs(obj.coef[0]) < 1.0e-16)
    {
      cubic.coef[0] = obj.coef[1];
      cubic.coef[1] = obj.coef[2];
      cubic.coef[2] = obj.coef[3];
      cubic.coef[3] = obj.coef[4];
      cubic.n = 3;
      return (solve_cubic(cubic, results));
    }
  fill_var_tab(var, obj);
  return (test_solve_cubic(var, results, roots));
}
