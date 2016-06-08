/*
** raytracer.h for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Wed May 29 23:48:02 2013 guillaume fillon
** Last update Sun Jun  9 16:37:42 2013 nicolas bridoux
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <mlx.h>
# include "object.h"
# include "bmp.h"
# include "color.h"
# include "vector.h"

# define EPSILON	0.00000000000001

# define RANGE		1000
# define UNUSED		__attribute__((unused))
# define NTHREAD	4
# define MAX_X	        1920
# define MAX_Y		1000

# define READ		4096
# define ESC		65307

# define DECIMAL	"0123456789"
# define HEXA		"0123456789ABCDEF"

# define SIZE_TAB	(MAX_X * OCTAVES) * (MAX_Y * OCTAVES)
# define NOTHING	0
# define LINE		1
# define CURV		2
# define OCTAVES	8
# define PAS		128
# define S1		0.25
# define S2		0.5
# define S3		0.75
# define TRUE		1
# define FALSE		0

# define MIN(x, y)	((x) < (y)) ? (x) : (y)
# define MIN2(x, y)	((x) < (y) && (x) > 0) ? (x) : (y)
# define MAX(x, y)	((x) > (y)) ? (x) : (y)
# define RADIAN(x)	(M_PI * (x) / 180)
# define ABS(x)		((x < 0) ? (-x) : (x))

# define TWO_PI		(2 * M_PI)
# define TWO_PI_3	(M_PI * (2 / 3))
# define FOUR_PI_3	(M_PI * (4 / 3))
# define GOLDEN_RATIO	((1 + sqrt(5.0)) / 2)

typedef struct	s_spot t_spot;
struct		s_spot
{
  t_vector	pos;
  t_color	color;
  t_color	color_tmp;
  double	intensity;
};

typedef struct	s_cam t_cam;
struct		s_cam
{
  t_vector	pos;
  t_vector	rot;
  t_vector	v;
};

typedef struct	s_mlx t_mlx;
struct		s_mlx
{
  void		*init;
  void		*win;
  void		*img;
  void		*red_img;
};

typedef struct	s_rt t_rt;
struct		s_rt
{
  uint		start;
  uint		end;
  int		first_passage;
  char		filter_background;
  char		filter_objects;
  char		filter_type;
  char		antialiasing;
  double	amb;
  double	gamma;
  char		contrast;
  int		contrast_color_one;
  int		contrast_color_two;
  int		max_refl;
  t_bmp_header	header;
  t_cam		*eye;
  t_obj		**objs;
  t_spot	**spots;
  t_mlx		*mlx;
};

typedef struct	s_sol t_sol;
struct		s_sol
{
  double	coef[5];
  int		n;
};

void		generate_scene_thread(t_rt *scene);
void		*generate_scene(void *data);
uint		raytracer(t_rt *scene, double x, double y);
t_color		find_max_color(t_spot **spots);
t_color		diffuse_light(double angle, t_obj *o, t_spot cspot);
t_vector	calc_normal(t_cam *eye, t_obj *o, t_vector p);
t_color		specular_light(t_obj *o, t_spot cs, t_rt *s, t_vector v[4]);
t_color		phong_light(t_spot cspot, t_obj *o, t_rt *scene, double k);

int		shaded(t_spot cur_spot, t_obj *o, t_rt *scene, double k);
uint		msaa(int i, int j, t_rt *s);
uint		apply_effects(t_rt *scene, t_obj *o, t_vector pixel, double k);
t_color		apply_light(t_rt *scene, t_obj *o, double k);
t_color		obj_effects(t_rt *scene, t_obj *o, t_vector pixel, double k);
t_vector	waves(t_vector n, t_vector normal_perturb, t_vector p);
t_color		apply_perlin(int x, int y, t_obj *obj);
double		perlin_noise(double x, double y, t_perlin perlin);

t_color		apply_texture(t_rt *scene, t_obj *obj, double k);
void		load_texture(t_obj **tab);
void		fill_random_tab(void);
uint		checkerboard(t_obj *obj, t_rt *scene, double k);
t_color		fade_checkerboard(t_rt *scene, t_obj *o, double k);
t_color		add_filter(t_rt *s, t_color color);
t_color		get_contrast(uint color1, uint color2, t_color color);
t_color		gamma_correction(t_rt *scene, t_color color);

double		check_limit(t_vector p, t_obj *o);

#endif  /* !RAYTRACER_H_ */
