/*
** get_spots.c for get_spots.c in /home/bridou_n/Raytracer/new/src
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Fri May 31 14:06:04 2013 nicolas bridoux
** Last update Sun Jun  9 15:46:24 2013 guillaume fillon
*/

#include "parsing.h"
#include "utils.h"

static int	nb_spots(char *file)
{
  int		i;
  int		count;

  count = 1;
  i = -1;
  while (file[++i])
    if (!my_strncmp(&file[i], "<object type=\"spot\">", 19))
      ++count;
  return (++count);
}

static void	init_spot(t_spot *spot)
{
  spot->pos = new_vector(150, 0, 550);
  spot->color = new_color(0x00, 0x0CC, 0xFF);
  spot->color_tmp = new_color(0, 0, 0);
  spot->intensity = 0.6;
}

static void	fill_infos_spot(t_spot *spot, char *file, int *i, int pos)
{
  while (END_BALISE)
    if (!pos)
      {
	if (!my_strncmp(&file[*i], "x=\"", 3))
	  spot->pos.x = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "y=\"", 3))
	  spot->pos.y = strtol(&file[*i + 3], NULL, 10);
	if (!my_strncmp(&file[*i], "z=\"", 3))
	  spot->pos.z = strtol(&file[*i + 3], NULL, 10);
      }
    else if (pos == 1)
      {
	if (!my_strncmp(&file[*i], "color=\"", 7))
	  spot->color = int_to_rgb(strtoul(&file[*i + 7], NULL, 16));
      }
    else
      {
	if (!my_strncmp(&file[*i], "intensity=\"", 11))
	  spot->intensity = strtod(&file[*i + 11], NULL);
      }
}

static void	delete_spot(char *file, int k, int dif, int *i)
{
  while (dif >= 0 && dif--)
    shift(file, k);
  *i = -1;
}

t_spot		**get_spots(char *file, int i, int j, int k)
{
  t_spot	**tab;

  if (!(tab = malloc(sizeof(t_spot *) * nb_spots(file))))
    my_error("Not enough memory\n", 1);
  while (file[++i])
    if (!my_strncmp(&file[i], "<object type=\"spot\">", 19))
      {
	if (!(tab[++j] = malloc(sizeof(t_spot))))
	  my_error("Not enough memory\n", 1);
	init_spot(tab[j]);
	k = i;
	while (file[++i] && my_strncmp(&file[i], "</object>", 9))
	  {
	    if (!my_strncmp(&file[i], "<pos ", 5))
	      fill_infos_spot(tab[j], file, &i, 0);
	    if (!my_strncmp(&file[i], "<color ", 7))
	      fill_infos_spot(tab[j], file, &i, 1);
	    if (!my_strncmp(&file[i], "<intensity ", 11))
	      fill_infos_spot(tab[j], file, &i, 2);
	  }
	delete_spot(file, k, (i + 9) - k, &i);
      }
  tab[++j] = NULL;
  return ((!j) ? (NULL) : (tab));
}
