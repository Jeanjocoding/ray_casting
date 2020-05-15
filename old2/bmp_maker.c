#include "bmp.h"
#include "cub3d.h"

int     initialize_bmp(t_bmpHeader *head)
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

int     set_bmp(t_bmpHeader *head, t_data *img_file)
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

int     write_bmp(int fd, t_bmpHeader *head, t_data *img_file, int img_size)
{
/*    write(fd, &head->type, 2);
    write(fd, &head->size, 4);
    write(fd, &head->reserved1, 2);
    write(fd, &head->reserved2, 4);*/
    char    *test;
    int i;
    int line;

    i = 0;
    test = ft_strdup("hello");
    ft_printf("head type : %x\n", head->type);
    ft_printf("size header : %d\n", sizeof(*head));
    ft_printf("size int_ptr : %d\n", sizeof(img_file->int_ptr));
    write(fd, head, sizeof(t_bmpHeader));
/*    while (i < img_size)
    {
        ft_printf("tab[%d] = %d\n", i, img_file->int_ptr[i]);
        i++;
    }*/
//    write(fd, img_file->int_ptr, img_size);
    
    img_size = img_size / 4;
    line = img_size / img_file->img_height;
    img_size -= line;
    while (img_size >= 0)
    {
        ft_printf("tab[%d] = %d\n", img_size, img_file->int_ptr[img_size]);
        write(fd, &((img_file->int_ptr)[img_size]), line * 4);
        img_size -= line;
    }

//    write(fd, test, 5);
//    write(fd, "\0", 1);
    return (0);
}


