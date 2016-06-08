/*
** my_pixel_put_to_image.c for my_pixel_put_to_image.c in /home/bridou_n//Tests
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Mon Nov 12 12:26:42 2012 nicolas bridoux
** Last update Sun Jun  9 14:44:37 2013 guillaume fillon
*/

#include "utils.h"

void	pixel_put(void *img, int x, int y, int color)
{
  int	bpp;
  int	sizeline;
  int	endian;
  char	*data;

  data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  if (!endian)
    {
      data[(x * bpp / 8) + (y * sizeline) + 2] = color >> 16;
      data[(x * bpp / 8) + (y * sizeline) + 1] = color >> 8 % 256;
      data[(x * bpp / 8) + (y * sizeline)] = color % 512;
    }
  else
    {
      data[(x * bpp / 8) + (y * sizeline)] = color % 512;
      data[(x * bpp / 8) + (y * sizeline) + 1] = color >> 8 % 256;
      data[(x * bpp / 8) + (y * sizeline) + 2] = color >> 16;
    }
}
