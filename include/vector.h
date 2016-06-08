/*
** vector.h for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:11:59 2013 guillaume fillon
** Last update Sun Jun  9 15:48:09 2013 guillaume fillon
*/

#ifndef VECTOR_H_
# define VECTOR_H_

typedef struct	s_cam t_cam;
typedef struct	s_obj t_obj;

typedef struct	s_vector t_vector;
struct		s_vector
{
  double	x;
  double	y;
  double	z;
};

t_vector	new_vector(double x, double y, double z);
t_vector	eq_parametric(t_vector v1, t_vector v2, double k);
double		dot_product(t_vector v1, t_vector v2);
double		get_norm(t_vector vec);
t_vector	normalize(t_vector vec);
t_vector	scale_vector(t_vector vec, double k);
t_vector	sum_vector(t_vector v1, t_vector v2);
t_vector	sub_vector(t_vector v1, t_vector v2);
t_vector	mult_vector(t_vector v1, t_vector v2);
double		get_angle(t_vector vec1, t_vector vec2);
t_vector	vec_reflective(t_vector vec, t_vector n);
t_vector	rotate_vector(t_vector vec, t_vector rot, int j);
t_vector	translate_vector(t_vector vec, t_vector trans, int j);
void		move_object(t_cam *eye, t_obj *obj, int j);

t_vector	rotate_x(t_vector vec, double angle);
t_vector	rotate_y(t_vector vec, double angle);
t_vector	rotate_z(t_vector vec, double angle);

#endif /* !VECTOR_H_ */
