/*
** utils.h for RT in /home/fillon_g/projects/tek1/igraph/raytracer-2017-bridou_n
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  9 14:38:07 2013 guillaume fillon
** Last update Sun Jun  9 14:43:32 2013 guillaume fillon
*/

#ifndef UTILS_H_
# define UTILS_H_

# include "raytracer.h"

char	*read_fd(const int fd);

char	*my_itoa(int i, char *b);
void	my_putchar(char c);
void	my_putstr(char *str);
char	*my_realloc(char *str, int size, int *j);
char	*my_strcat(char *s1, char *s2);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
int	my_strlen(char *str);
int	len_tab(void **tab);
void	my_error(char *str, int quit);
int	my_strncmp(char *s1, char *s2, int n);

char	double_are_same(double a, double b);
double	modulo(double nb1, double nb2);
void	shift(char *str, int i);
t_rt	copy_scene(t_rt *s);

void	pixel_put(void *img, int x, int y, int color);
int	handle_expose(void *data);
int	handle_key(int keycode, t_rt *scene);
t_mlx	*init_gui(t_mlx *e);

#endif /* !UTILS_H_ */
