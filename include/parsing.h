/*
** parsing.h for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:17:45 2013 guillaume fillon
** Last update Sun Jun  9 16:34:18 2013 nicolas bridoux
*/

#ifndef PARSING_H_
# define PARSING_H_

# include "raytracer.h"

# define END_BALISE	file[++(*i)] && my_strncmp(&file[*i], "/>", 2)

typedef struct	s_type t_type;
struct		s_type
{
  char		*name;
  double	(*inter)(t_cam *, t_obj *);
  t_vector	(*normal)(t_cam *, t_obj *, t_vector);
};

typedef struct	s_pars t_pars;
struct		s_pars
{
  char		*name;
  void		(*func)(char *, int *, t_obj *);
};

int	parse_scene(t_rt *s, t_cam *eye, char *name);
t_cam	*get_eye(char *file, t_cam *eye);
t_obj	**get_objects(char *file);
t_spot	**get_spots(char *file, int i, int j, int k);
void	fill_rot(char *file, int *i, t_obj *obj);
void	fill_pos(char *file, int *i, t_obj *obj);
void	fill_color(char *file, int *i, t_obj *obj);
void	fill_size(char *file, int *i, t_obj *obj);
void	fill_shiny(char *file, int *i, t_obj *obj);
void	fill_infos_obj(char *file, int *i, t_obj *obj);
void	fill_diffuse(char *file, int *i, t_obj *obj);
void	fill_color_perlin(char *file, int *i, t_obj *obj);
void	fill_perlin(char *file, int *i, t_obj *obj);
void	fill_specular(char *file, int *i, t_obj *obj);
void	fill_second_size(char *file, int *i, t_obj *obj);
void	fill_checkerboard(char *file, int *i, t_obj *obj);
void	fill_texture(char *file, int *i, t_obj *obj);
void	fill_bump_map(char *file, int *i, t_obj *obj);
void	fill_limit(char *file, int *i, t_obj *obj);

#endif /* !PARSING_H_ */
