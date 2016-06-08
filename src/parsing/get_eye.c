/*
** get_eye.c for get_eye.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 12:43:26 2013 nicolas bridoux
** Last update Sun Jun  9 15:44:29 2013 guillaume fillon
*/

#include "parsing.h"
#include "utils.h"

static void	init_eye(t_cam *eye)
{
  eye->pos = new_vector(-1500, 0.0, 150);
  eye->rot = new_vector(0.0, 0.0, 0.0);
}

static void	fill_infos_eye(t_cam *eye, char *file, int *i, int pos)
{
  while (END_BALISE)
    if (pos)
      {
	if (!my_strncmp(&file[*i], "x=\"", 3))
	  eye->pos.x = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "y=\"", 3))
	  eye->pos.y = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "z=\"", 3))
	  eye->pos.z = strtol(&file[*i + 3], NULL, 10);
      }
    else
      {
	if (!my_strncmp(&file[*i], "x=\"", 3))
	  eye->rot.x = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "y=\"", 3))
	  eye->rot.y = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "z=\"", 3))
	  eye->rot.z = strtol(&file[*i + 3], NULL, 10);
      }
}

t_cam	*get_eye(char *file, t_cam *eye)
{
  int	i;
  int	k;
  int	dif;

  i = -1;
  init_eye(eye);
  while (file[++i])
    if (!my_strncmp(&file[i], "<object type=\"eye\">", 19))
      {
  	k = i;
  	while (file[++i] && my_strncmp(&file[i], "</object>", 9))
  	  {
  	    if (!my_strncmp(&file[i], "<rotate ", 8))
	      fill_infos_eye(eye, file, &i, 0);
  	    if (!my_strncmp(&file[i], "<pos ", 5))
	      fill_infos_eye(eye, file, &i, 1);
  	  }
	dif = (i + 9) - k;
	while (dif--)
	  shift(file, k);
      }
  return (eye);
}
