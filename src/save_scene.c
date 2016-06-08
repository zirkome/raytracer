/*
** save_scene.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-2017-bridou_n/new/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  2 21:35:32 2013 guillaume fillon
** Last update Sun Jun  9 21:19:36 2013 guillaume fillon
*/

#include "raytracer.h"
#include "utils.h"
#include "bmp.h"

static char	*get_filename()
{
  char		*tmp;
  char		*filename;
  static uint	i;

  i = 1;
  if ((filename = malloc(256)) == NULL)
    return (NULL);
  if ((tmp = malloc(11)) == NULL)
    return (NULL);
  while (i < 0xffffffff)
    {
      tmp = my_itoa(i, tmp);
      filename = my_strcpy(filename, "save-");
      filename = my_strcat(filename, tmp);
      filename = my_strcat(filename, ".bmp");
      if (access(filename, F_OK))
	return (filename);
      ++i;
    }
  return (NULL);
}

static void	write_byte(char *img, char *data, int i[3], int sl)
{
  img[i[2]] = data[(i[0] * sl) + i[1]];
  img[i[2] + 1] = data[(i[0] * sl) + i[1] + 1];
  img[i[2] + 2] = data[(i[0] * sl) + i[1] + 2];
  i[1] += 4;
  i[2] += 3;
}

static int	write_to_bmp(char *data, int sl)
{
  char		img[MAX_X * MAX_Y * 4];
  char		*filename;
  int		fd;
  int		i[3];

  filename = get_filename();
  if ((fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
    return (-1);
  write_bmp_header(fd);
  i[0] = MAX_Y - 1;
  i[2] = 0;
  while (i[0] >= 0)
    {
      i[1] = 0;
      while (i[1] < sl)
	write_byte(img, data, i, sl);
      --i[0];
    }
  write(fd, img, MAX_Y * MAX_X * 4);
  write(1, "Generated scene saved as ", 25);
  write(1, filename, my_strlen(filename));
  write(1, "\n", 1);
  return (-1);
}

void	save_scene(void *img)
{
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;

  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  if (write_to_bmp(data, sizeline) == -1)
    return;
}
