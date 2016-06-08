/*
** main.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 13:50:20 2013 guillaume fillon
** Last update Sun Jun  9 15:15:38 2013 guillaume fillon
*/

#include "raytracer.h"
#include "utils.h"
#include "parsing.h"

int		init_scene(t_rt *s, t_cam *c, t_mlx *e, char *name)
{
  if ((s->mlx = e) == NULL)
    return (EXIT_FAILURE);
  if (parse_scene(s, c, name))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		main_exception(int ac)
{
  if (ac < 2)
    write(2, "Please give us an xml scene as parameter.\n"
	  "Usage:\n\t./rt scene[.xml]\n", 67);
  else
    write(2, "Can't init the Xlib or the window. "
	  "Please retry later (...or not).\n", 67);
  return (EXIT_FAILURE);
}

int		main(UNUSED int ac, UNUSED char *av[])
{
  t_rt		scene[NTHREAD];
  t_mlx		mlx;
  t_cam		eye[NTHREAD];
  int		i;

  if (ac < 2 || !init_gui(&mlx))
    return (main_exception(ac));
  if (init_scene(&scene[0], &eye[0], &mlx, av[1]) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  i = 0;
  while (++i < NTHREAD)
    scene[i] = copy_scene(&scene[0]);
  if ((mlx.win = mlx_new_window(mlx.init, MAX_X, MAX_Y, "RT")) == NULL)
    return (EXIT_FAILURE);
  generate_scene_thread(scene);
  mlx_expose_hook(mlx.win, &handle_expose, &mlx);
  mlx_key_hook(mlx.win, &handle_key, scene);
  mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
  mlx_loop(mlx.init);
  return (EXIT_SUCCESS);
}
