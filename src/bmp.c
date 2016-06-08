/*
** bmp.c for RT in /home/fillon_g/projets/tek1/igraph/raytracer-2017-bridou_n/new/include
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  2 20:42:42 2013 guillaume fillon
** Last update Sun Jun  9 14:54:42 2013 guillaume fillon
*/

#include "utils.h"
#include "bmp.h"

int		write_bmp_header(int fd)
{
  t_bmp_header	header;

  header.file_type = BMP_MAGIC;
  header.file_size = 54 + (MAX_Y * MAX_X * 4);
  header.reserved1 = 0x0000;
  header.reserved2 = 0x0000;
  header.bitmap_offset = 0x00000036;
  header.header_size = 0x00000028;
  header.width = MAX_X;
  header.height = MAX_Y;
  header.planes = 0x0001;
  header.bits_per_pixel = 0x0018;
  header.compression = 0x00000000;
  header.bitmap_size = MAX_Y * MAX_X * 4;
  header.x_res = 0x00000B13;
  header.y_res = 0x00000B13;
  header.colors_used = 0x00000000;
  header.colors_important = 0x00000000;
  if (write(fd, &header, sizeof(header)) == -1)
    return (-1);
  return (0);
}

static int	check_header(t_bmp_header *hdr, char *name)
{
  if (hdr->file_type != BMP_MAGIC)
    {
      my_error(name, 0);
      my_error(" is not a bitmap file.\n", 0);
      return (-1);
    }
  if (hdr->bits_per_pixel != 24)
    {
      my_error(name, 0);
      my_error(" hasn't a 24bits per pixel\n", 0);
      return (-1);
    }
  return (0);
}

static int	load_header(t_bmp_header *hdr, char *name)
{
  int		fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    {
      my_error(name, 0);
      my_error(" : Can't open texture file\n", 0);
      return (fd);
    }
  if (read(fd, hdr, sizeof(*hdr)) != sizeof(*hdr))
    return (-1);
  if (check_header(hdr, name) == -1)
    return (-1);
  return (fd);
}

unsigned char		*load_bmp(char *name, t_bmp_header *hdr, int i)
{
  int			size;
  unsigned char		*tab;
  int			fd;

  if ((fd = load_header(hdr, name)) == -1)
    return (NULL);
  size = (hdr->width) * (hdr->height) * 3;
  if (!(tab = malloc(sizeof(unsigned char) * size)))
    return (NULL);
  i = -1;
  while (++i < size)
    if (read(fd, &tab[size - i - 1], sizeof(char)) <= 0)
      {
	free(tab);
	close(fd);
	return (NULL);
      }
  close(fd);
  return (tab);
}
