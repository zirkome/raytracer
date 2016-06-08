/*
** raytracer.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-sallab_f/new
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu May 30 15:26:50 2013 guillaume fillon
** Last update Sun Jun  9 21:11:00 2013 guillaume fillon
*/

#include <pthread.h>
#include "raytracer.h"
#include "utils.h"

pthread_mutex_t	g_lock[2];

uint		raytracer(t_rt *scene, double x, double y)
{
  int		i;
  double	k[2];
  uint		color;
  t_obj		*nearest;
  t_cam		*eye;

  i = -1;
  k[0] = -1.0;
  nearest = NULL;
  eye = scene->eye;
  eye->v = new_vector(RANGE, (MAX_X / 2) - x, (MAX_Y / 2) - y);
  eye->v = rotate_vector(eye->v, eye->rot, 1);
  eye->v = normalize(eye->v);
  while (scene->objs[++i] != NULL)
    {
      move_object(eye, scene->objs[i], -1);
      k[1] = scene->objs[i]->inter(eye, scene->objs[i]);
      move_object(eye, scene->objs[i], 1);
      if ((k[1] > 0.0 && k[0] < 0.0) || (k[1] <= k[0] && k[1] > 0.0))
	k[0] = k[1];
      if (double_are_same(k[0], k[1]) && k[0] > 0.0)
	nearest = scene->objs[i];
    }
  color = apply_effects(scene, nearest, new_vector(x, y, 0.0), k[0]);
  return (color);
}

void		*generate_scene(void *data)
{
  t_rt		*scene;
  uint		i;
  uint		j;

  scene = (t_rt *) data;
  i = scene->start;
  while (i < scene->end)
    {
      j = 0;
      while (j < MAX_Y)
	{
	  pixel_put(scene->mlx->img, i, j, msaa(i, j, scene));
	  ++j;
	}
      pthread_mutex_lock(&g_lock[0]);
      mlx_put_image_to_window(scene->mlx->init,
			      scene->mlx->win, scene->mlx->img, 0, 0);
      pthread_mutex_unlock(&g_lock[0]);
      ++i;
    }
  pthread_exit(NULL);
  return (NULL);
}

void		generate_scene_thread(t_rt *scene)
{
  int		i;
  pthread_t	thread[NTHREAD];

  if (pthread_mutex_init(&g_lock[0], NULL) != 0)
    {
      write(2, "Mutex init failed\n", 18);
      return ;
    }
  i = -1;
  while (++i < NTHREAD)
    {
      scene[i].start = i * (MAX_X / NTHREAD);
      scene[i].end = (i + 1) * ((MAX_X) / NTHREAD);
      pthread_create(&thread[i], NULL, generate_scene, (void *) &scene[i]);
    }
  i = -1;
  while (++i < NTHREAD / ((scene->antialiasing > 1) ? 1 : 2))
    pthread_join(thread[i], NULL);
}
