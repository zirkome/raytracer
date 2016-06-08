/*
** mlx.c for mlx.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 12:19:41 2013 nicolas bridoux
** Last update Sun Jun  9 21:09:15 2013 guillaume fillon
*/

#include "utils.h"

static void	my_free_tab(void **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}

int	handle_expose(void *data)
{
  t_mlx	*p;

  p = (t_mlx *)data;
  mlx_put_image_to_window(p->init, p->win, p->img, 0, 0);
  return (EXIT_SUCCESS);
}

int	handle_key(int keycode, t_rt *scene)
{
  int	i;

  if (keycode == ESC)
    {
      i = -1;
      while (++i < NTHREAD)
	{
	  my_free_tab((void **)scene[i].objs);
	  my_free_tab((void **)scene[i].spots);
	}
      exit(EXIT_SUCCESS);
    }
  if (keycode == 's' || keycode == 'b')
    save_scene(scene[0].mlx->img);
  return (EXIT_SUCCESS);
}

t_mlx		*init_gui(t_mlx *e)
{
  if ((e->init = mlx_init()) == NULL)
    return (NULL);
  if ((e->img = mlx_new_image(e->init, MAX_X, MAX_Y)) == NULL)
    {
      write (2, "Can't create new image. Abort.\n", 31);
      return (NULL);
    }
  return (e);
}
