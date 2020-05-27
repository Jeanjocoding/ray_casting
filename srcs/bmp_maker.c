#include "bmp.h"
#include "cub3d.h"

int	initialize_bmp(t_bmpHeader *head)
{
	head->type = 0x4d42;
	head->size = 0;
	head->reserved1 = 0;
	head->reserved2 = 0;
	head->offset = 0;
	head->dib_header_size = 0;
	head->width_px = 0;
	head->height_px = 0;
	head->num_planes = 1;
	head->bits_per_pixel = 32;
	head->compression = 0;
	head->image_size_bytes = 0;
	head->x_resolution_ppm = 0;
	head->y_resolution_ppm = 0;
	head->num_colors = 0;
	head->important_colors = 0;
	return (0);
}

int	set_bmp(t_bmpHeader *head, t_data *img_file)
{
	head->type = 0x4d42;
	head->size = 54 + img_file->img_width * img_file->img_height;
	head->reserved1 = 0;
	head->reserved2 = 0;
	head->offset = 54;
	head->dib_header_size = 40;
	head->width_px = img_file->img_width;
	head->height_px = img_file->img_height;
	head->num_planes = 1;
	head->bits_per_pixel = 32;
	head->compression = 0;
	head->image_size_bytes = img_file->img_width * img_file->img_height;
	head->x_resolution_ppm = 0;
	head->y_resolution_ppm = 0;
	head->num_colors = 0;
	head->important_colors = 0;
	return (0);
}

int	write_bmp(int fd, t_bmpHeader *head, t_data *img_file, int img_size)
{
	int		i;
	int		line;

	i = 0;
	write(fd, head, sizeof(t_bmpHeader));
	img_size = img_size / 4;
	line = img_size / img_file->img_height;
	img_size -= line;
	while (img_size >= 0)
	{
		write(fd, &((img_file->int_ptr)[img_size]), line * 4);
		img_size -= line;
	}
	return (0);
}
