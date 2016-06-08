/*
** color.h for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:09:55 2013 guillaume fillon
** Last update Sun Jun  9 16:38:00 2013 nicolas bridoux
*/

#ifndef COLOR_H_
# define COLOR_H_

# include <stdlib.h>

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define ABS_COLOR(x)	((x) > 255) ? (255) : (x)

typedef struct	s_color t_color;
struct		s_color
{
  double	r;
  double	g;
  double	b;
};

t_color		fade_rgb(t_color color1, t_color color2);
double		avg_rgb(t_color color);
t_color		int_to_rgb(uint color);
uint		rgb_to_int(t_color c);
t_color		color_add(t_color c1, t_color c2);
t_color		color_add2(t_color c1, t_color c2);
t_color		color_mult(t_color c1, t_color c2);
t_color		color_scale(t_color c1, double k);
t_color		new_color(double r, double g, double b);

#endif /* !COLOR_H_ */
