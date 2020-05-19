/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:38:39 by tlucille          #+#    #+#             */
/*   Updated: 2020/03/11 15:29:44 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
extern int	g_screenwidth;
extern int	g_screenheight;
extern double	*Zbuffer;

t_sprites	*sprite_on_screen(t_sprites *sprite, t_data *g_tex_list, t_data *main_img)
{
	int		m_coor[2];
	int		tex_coor[2];
	t_data	*tex_img;
	int		d;
	int		*addr_ptr;

	m_coor[0] = sprite->drawStartX;
	m_coor[1] = sprite->drawStartY;
	tex_img = get_right_tex(4, g_tex_list);
	while (m_coor[0] < sprite->drawEndX)
	{
		tex_coor[0] = (int)(256 * (m_coor[0] - (-sprite->spriteWidth / 2 + sprite->screenX)) * tex_img->img_width / sprite->spriteWidth) / 256;
		if (sprite->transformY > 0 && m_coor[0] > 0 && m_coor[0] < g_screenwidth && sprite->transformY < Zbuffer[m_coor[0]])
		{
			while (m_coor[1] < sprite->drawEndY)
			{
				d = (m_coor[1]) * 256 - g_screenheight * 128 + sprite->spriteHeight * 128;
				tex_coor[1] = ((d * tex_img->img_height) / sprite->spriteHeight) / 256;
				addr_ptr = tex_img->int_ptr + (tex_coor[1] * tex_img->img_width + tex_coor[0]);
				if (((int)(*addr_ptr) & 0x00FFFFFF) != 0) 
					my_mlx_pixel_put(main_img, m_coor[0], m_coor[1], (int)(*addr_ptr));
				m_coor[1]++;
			}
			m_coor[1] = sprite->drawStartY;
			
		}
		m_coor[0]++;
	}
	return (sprite);
}

t_sprites	*sprite_height_width(t_sprites *sprite_list)
{
		sprite_list->screenX = (int)((g_screenwidth / 2) *
			(1 + sprite_list->transformX / sprite_list->transformY));
		sprite_list->spriteHeight = abs((int)(g_screenheight /
			(sprite_list->transformY)));
		sprite_list->drawStartY = -sprite_list->spriteHeight 
			/ 2 + g_screenheight / 2;
		if (sprite_list->drawStartY < 0)
			sprite_list->drawStartY = 0;
		sprite_list->drawEndY = sprite_list->spriteHeight /
			2 + g_screenheight / 2;
		if (sprite_list->drawEndY >= g_screenheight)
			sprite_list->drawEndY = g_screenheight - 1;
		sprite_list->spriteWidth = abs((int)(g_screenheight / 
			(sprite_list->transformY)));
		sprite_list->drawStartX = -sprite_list->spriteWidth /
			2 + sprite_list->screenX;
		if (sprite_list->drawStartX < 0)
			sprite_list->drawStartX = 0;
		sprite_list->drawEndX = sprite_list->spriteWidth / 
			2 + sprite_list->screenX;
		if (sprite_list->drawEndX >= g_screenwidth)
			sprite_list->drawEndX = g_screenwidth - 1;
		return (sprite_list);
}

t_sprites	*put_sprites(t_vars *vars, t_sprites *sprite_list, t_data *g_tex_list, t_data *main_img)
{
	t_fov	fov;

	fov = vars->fov;
	while (sprite_list != NULL)
	{
		sprite_list->spriteX = sprite_list->x - fov.posX;
		sprite_list->spriteY = sprite_list->y - fov.posY;
		sprite_list->invDet = 1.0 / (fov.planeX * fov.dirY - fov.dirX * fov.planeY);
		sprite_list->transformX = sprite_list->invDet * (fov.dirY * sprite_list->spriteX - fov.dirX * sprite_list->spriteY);
		sprite_list->transformY = sprite_list->invDet * (-fov.planeY * sprite_list->spriteX + fov.planeX * sprite_list->spriteY);
		sprite_height_width(sprite_list);
		sprite_on_screen(sprite_list, g_tex_list, main_img);
		sprite_list = sprite_list->next;
	}
	return (sprite_list);
}
