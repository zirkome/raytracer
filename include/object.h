/*
** object.h for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:57:28 2013 guillaume fillon
** Last update Sun Jun  9 16:31:51 2013 nicolas bridoux
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "color.h"
# include "vector.h"

typedef struct	s_cam t_cam;
typedef struct	s_sol t_sol;
typedef struct	s_vector t_vector;

typedef struct	s_perlin t_perlin;
struct		s_perlin
{
  int		color_one;
  int		color_two;
  int		color_tree;
  int		type;
  double	here;
  double	right;
  double	down;
  double	diag;
  double	coef;
  double	pers;
};

typedef struct	s_texture t_texture;
struct		s_texture
{
  char		*name;
  unsigned char	*img;
  int		height;
  int		width;
};

typedef struct	s_obj t_obj;
struct		s_obj
{
  t_vector	rot;
  t_vector	trans;
  t_vector	limit_max;
  t_vector	limit_min;
  t_perlin	perlin;
  t_texture	texture;
  double	specular;
  double	diffuse;
  double	size;
  double	second_size;
  double	shiny;
  t_color	color;
  char		limit;
  char		checkerboard;
  int		checkerboard_color;
  int		checkerboard_size;
  t_vector	normal_perturb;

  t_vector	(*normal)(t_cam *, t_obj *, t_vector);
  double	(*inter)(t_cam *, t_obj *);
};

double		solve_eq(double a, double b, double delta);
t_obj		*new_object(double size, t_vector trans, t_vector rot);

t_vector	normal_sphere(t_cam *eye, t_obj *obj, t_vector p);
double		inter_sphere(t_cam *eye, t_obj *o);

t_vector	normal_paraboloide(t_cam *eye, t_obj *obj, t_vector p);
double		inter_paraboloide(t_cam *eye, t_obj *o);

t_vector	normal_cylinder(t_cam *eye, t_obj *obj, t_vector p);
double		inter_cylinder(t_cam *eye, t_obj *o);

t_vector	normal_plane(t_cam *eye, t_obj *obj, t_vector p);
double		inter_plane(t_cam *eye, t_obj *plane);

double		inter_tore(t_cam *eye, t_obj *o);
t_vector	normal_tore(t_cam *eye, t_obj *obj, t_vector p);

t_vector	normal_ruban(t_cam *eye, t_obj *obj, t_vector p);
double		inter_ruban(t_cam *eye, t_obj *o);

t_vector	normal_cone(t_cam *eye, t_obj *obj, t_vector p);
double		inter_cone(t_cam *eye, t_obj *o);

double		inter_cube(t_cam *eye, t_obj *o);
t_vector	normal_cube(t_cam *eye, t_obj *obj, t_vector p);

t_vector	normal_hyperboloide(t_cam *eye, t_obj *obj, t_vector p);
double		inter_hyperboloide(t_cam *eye, t_obj *o);

double		find_min_root(int nb_roots, double *roots);
int		solve_cubic(t_sol obj, double *results);
int		solve_quadratic(t_sol obj, double *results);
int		solve_quartic(t_sol obj, double *results);

#endif /* !OBJECT_H_ */
