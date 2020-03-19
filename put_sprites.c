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

#include "lodev.h"
extern int	screenWidth;
extern int	screenHeight;
extern int	*Zbuffer;

t_sprites	*sprite_on_screen(t_sprites *sprite, t_data *tex_list, t_data *main_img)
{
	int		stripe;
	int		texX;
	int		texY;
	int		color;
	t_data	*tex_img;
	int		y;
	int		d;
	int		*addr_ptr;
	int		step;

	stripe = sprite->drawStartX;
	y = sprite->drawStartY;
	tex_img = get_right_tex(4, tex_list);
	while (stripe < sprite->drawEndX)
	{
		texX = (int)(256 * (stripe - (-sprite->spriteWidth / 2 + sprite->screenX)) * tex_img->img_width / sprite->spriteWidth) / 256;
		if (sprite->transformY > 0 && stripe > 0 && stripe < screenWidth && sprite->transformY < Zbuffer[stripe])
		{
			while (y < sprite->drawEndY)
			{
				d = (y) * 256 - screenHeight * 128 + sprite->spriteHeight * 128;
				texY = ((d * tex_img->img_height) / sprite->spriteHeight) / 256;
				addr_ptr = tex_img->int_ptr + (texY * tex_img->img_width + texX);
				color = (int)(*addr_ptr);
				if ((color & 0x00FFFFFF) != 0) 
					my_mlx_pixel_put(main_img, stripe, y, color);
				y++;
			}
			y = sprite->drawStartY;
			
		}
		stripe++;


	}
	return (sprite);
}

t_sprites	*sprite_height_width(t_sprites *sprite_list)
{
		sprite_list->screenX = (int)((screenWidth / 2) *
			(1 + sprite_list->transformX / sprite_list->transformY));
		sprite_list->spriteHeight = abs((int)(screenHeight /
			(sprite_list->transformY)));
		sprite_list->drawStartY = -sprite_list->spriteHeight 
			/ 2 + screenHeight / 2;
		if (sprite_list->drawStartY < 0)
			sprite_list->drawStartY = 0;
		sprite_list->drawEndY = sprite_list->spriteHeight /
			2 + screenHeight / 2;
		if (sprite_list->drawEndY >= screenHeight)
			sprite_list->drawEndY = screenHeight - 1;
		sprite_list->spriteWidth = abs((int)(screenHeight / 
			(sprite_list->transformY)));
		sprite_list->drawStartX = -sprite_list->spriteWidth /
			2 + sprite_list->screenX;
		if (sprite_list->drawStartX < 0)
			sprite_list->drawStartX = 0;
		sprite_list->drawEndX = sprite_list->spriteWidth / 
			2 + sprite_list->screenX;
		if (sprite_list->drawEndX >= screenWidth)
			sprite_list->drawEndX = screenWidth - 1;
		return (sprite_list);
}

t_sprites	*put_sprites(t_vars *vars, t_sprites *sprite_list, t_data *tex_list, t_data *main_img)
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
		sprite_on_screen(sprite_list, tex_list, main_img);
		sprite_list = sprite_list->next;
	}




	return (sprite_list);
}
