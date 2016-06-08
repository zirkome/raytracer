/*
** parse_scene.c for parse_scene.c in /home/bridou_n/Raytracer/new/src/parsing
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 11:26:08 2013 nicolas bridoux
** Last update Sun Jun  9 15:51:21 2013 guillaume fillon
*/

#include "parsing.h"
#include "bmp.h"
#include "utils.h"

static void	get_scene_contrast(t_rt *s, char *file, int i)
{
  if (!my_strncmp(&file[i], "<contrast ", 10))
    {
      s->contrast = TRUE;
      while (file[++i] && my_strncmp(&file[i], "/>", 2))
	{
	  if (!my_strncmp(&file[i], "color1=\"", 8))
	    s->contrast_color_one = strtol(&file[i + 8], NULL, 16);
	  if (!my_strncmp(&file[i], "color2=\"", 8))
	    s->contrast_color_two = strtol(&file[i + 8], NULL, 16);
	}
    }
  if (!my_strncmp(&file[i], "<gamma ", 7))
    while (file[++i] && my_strncmp(&file[i], "/>", 2))
      if (!my_strncmp(&file[i], "gamma=\"", 7))
	s->gamma = strtod(&file[i + 7], NULL);
}

static void	parse_scene_balise(t_rt *s, char *file, int i)
{
  while (file[++i] && my_strncmp(&file[i], "</scene>", 8))
    {
      if (!my_strncmp(&file[i], "<ambient intensity=\"", 20))
	s->amb = strtod(&file[i + 20], NULL);
      if (!my_strncmp(&file[i], "<msaa threshold=\"", 17))
	s->antialiasing = strtol(&file[i + 17], NULL, 10);
      if (!my_strncmp(&file[i], "<filter ", 8))
	while (file[++i] && my_strncmp(&file[i], "/>", 2))
	  {
	    if (!my_strncmp(&file[i], "background=\"", 12))
	      s->filter_background = strtol(&file[i + 12], NULL, 10) % 2;
	    if (!my_strncmp(&file[i], "objects=\"", 9))
	      s->filter_objects = strtol(&file[i + 9], NULL, 10) % 2;
	    if (!my_strncmp(&file[i], "type=\"", 6))
	      s->filter_type = strtol(&file[i + 6], NULL, 10) % 8;
	  }
      get_scene_contrast(s, file, i);
    }
}

static void	get_scene_infos(char *file, t_rt *s)
{
  int		i;

  i = -1;
  s->amb = 0.0;
  s->antialiasing = 1;
  s->filter_background = FALSE;
  s->filter_objects = FALSE;
  s->filter_type = FALSE;
  s->contrast = FALSE;
  s->contrast_color_one = 0xFFFFFF;
  s->contrast_color_two = BLACK;
  s->gamma = GOLDEN_RATIO;
  while (file[++i])
    if (!my_strncmp(&file[i], "<scene>", 7))
      parse_scene_balise(s, file, i);
  if (s->antialiasing < 0)
    s->antialiasing = ABS(s->antialiasing);
  if (!s->antialiasing)
    ++s->antialiasing;
}

int	parse_scene(t_rt *s, t_cam *eye, char *name)
{
  int	fd;
  char	*file;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (EXIT_FAILURE);
  file = read_fd(fd);
  close(fd);
  if (!file)
    return (EXIT_FAILURE);
  get_scene_infos(file, s);
  s->eye = get_eye(file, eye);
  if (!(s->spots = get_spots(file, -1, -1, 0)))
    {
      my_error("Not enough spots\n", 0);
      return (EXIT_FAILURE);
    }
  if (!(s->objs = get_objects(file)))
    {
      my_error("Not enough objects\n", 0);
      return (EXIT_FAILURE);
    }
  load_texture(s->objs);
  free(file);
  return (EXIT_SUCCESS);
}
