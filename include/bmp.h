/*
** bmp.h for RT in /home/fillon_g/projets/tek1/igraph/raytracer-2017-bridou_n/new/include
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jun  2 20:37:58 2013 guillaume fillon
** Last update Sun Jun  9 16:29:42 2013 nicolas bridoux
*/

#ifndef BMP_H_
# define BMP_H_

# pragma pack(push, 1)

# define BMP_MAGIC	0x4D42

typedef struct		s_bmp_header
{
  unsigned short int	file_type;
  unsigned int		file_size;
  unsigned short int	reserved1;
  unsigned short int	reserved2;
  int			bitmap_offset;

  int			header_size;
  int			width;
  int			height;
  unsigned short int	planes;
  unsigned short int	bits_per_pixel;
  unsigned int		compression;

  unsigned int		bitmap_size;
  int			x_res;
  int			y_res;
  unsigned int		colors_used;
  unsigned int		colors_important;
}			t_bmp_header;

# pragma pack(pop)

int		write_bmp_header(int fd);
unsigned char	*load_bmp(char *name, t_bmp_header *hdr, int i);
void		save_scene(void *img);

#endif /* !BMP_H_ */
