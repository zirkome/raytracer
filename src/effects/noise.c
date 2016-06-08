/*
** noise.c for noise.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 18:55:04 2013 nicolas bridoux
** Last update Sun Jun  9 16:20:56 2013 guillaume fillon
*/

#include "raytracer.h"

double	g_tab_random[SIZE_TAB];

void	fill_random_tab(void)
{
  int	hauteur_max;
  int	longueur_max;
  int	i;

  longueur_max = (int)ceil(MAX_X * pow(2, OCTAVES  - 1)  / PAS);
  hauteur_max = (int)ceil(MAX_Y * pow(2, OCTAVES  - 1)  / PAS);
  srand(time(NULL));
  i = -1;
  while (++i < longueur_max * hauteur_max)
    g_tab_random[i] = ((double)rand()) / RAND_MAX;
}

double		interpolation(t_perlin p, double x, double y)
{
  double	i;
  double	k;
  double	a;
  double	b;

  a = p.here;
  b = p.right;
  i = a * (1 - ((1 - cos(x * M_PI)) / 2)) + p.down
    * ((1 - cos(x * M_PI)) / 2);
  k = b * (1 - ((1 - cos(x * M_PI)) / 2)) + p.diag
    * ((1 - cos(x * M_PI)) / 2);
  return  (i * (1 - ((1 - cos(y * M_PI)) / 2))
	   + k * ((1 - cos(y * M_PI)) / 2));
}

double		noise(double x, double y, t_perlin p)
{
  static int	longueur_max = 0;
  static int	k = 0;
  int		i;
  int		j;

  if (!k)
    {
      longueur_max = (int)ceil(MAX_X * pow(2, OCTAVES - 1)  / PAS);
      k = 1;
    }
  i = (x / PAS);
  j = (y / PAS);
  p.here = g_tab_random[(i * longueur_max + j)];
  p.down = g_tab_random[((i + 1) * longueur_max + j)];
  p.right = g_tab_random[(i * longueur_max + j + 1)];
  p.diag = g_tab_random[((i + 1) * longueur_max + j + 1)];
  return (interpolation(p, fmod(x / PAS, 1), fmod(y / PAS, 1)));
}

double		perlin_noise(double x, double y, t_perlin perlin)
{
  double	sum;
  double	p;
  int		f;
  int		i;

  i = -1;
  sum = 0;
  f = 1;
  p = 1;
  while (++i < OCTAVES)
    {
      sum += p * noise(x * f, y * f, perlin);
      p *= perlin.pers;
      f *= 2;
    }
  return (sum * (1 - perlin.pers) / (1 - p));
}
