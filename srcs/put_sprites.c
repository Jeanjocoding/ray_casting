/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   put_sprites.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tlucille <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/03/11 14:38:39 by tlucille		  #+#	#+#			 */
/*   Updated: 2020/03/11 15:29:44 by tlucille		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

extern int	g_screenwidth;
extern int	g_screenheight;
extern double	*g_zbuffer;

int			put_sprite_line(int m_coor[3], t_sprites *sprite,
		t_data *main_img, t_data *tex_img)
{
	int		tex_coor[2];
	int		*addr_ptr;
	int		d;

	while (m_coor[1] < sprite->drawendy)
	{
		d = (m_coor[1]) * 256 - g_screenheight * 128
			+ sprite->spriteheight * 128;
		tex_coor[1] = ((d * tex_img->img_height)
			/ sprite->spriteheight) / 256;
		addr_ptr = tex_img->int_ptr + (tex_coor[1]
			* tex_img->img_width + m_coor[2]);
		if (((int)(*addr_ptr) & 0x00FFFFFF) != 0)
			put_my_pixel(main_img, m_coor[0], m_coor[1],
				(int)(*addr_ptr));
		m_coor[1]++;
	}
	m_coor[1] = sprite->drawstarty;
	return (0);
}

t_sprites	*sprite_on_screen(t_sprites *sprite,
		t_data *g_tex_list, t_data *main_img)
{
	int		m_coor[3];
	int		tex_coor[2];
	t_data	*tex_img;

	m_coor[0] = sprite->drawstartx;
	m_coor[1] = sprite->drawstarty;
	tex_img = get_right_tex(4, g_tex_list);
	while (m_coor[0] < sprite->drawendx)
	{
		tex_coor[0] = (int)(256 * (m_coor[0] - (-sprite->spritewidth / 2 +
			sprite->screenx)) * tex_img->img_width / sprite->spritewidth) / 256;
		m_coor[2] = tex_coor[0];
		if (sprite->transformy > 0 && m_coor[0] > 0 && m_coor[0] < g_screenwidth
			&& sprite->transformy < g_zbuffer[m_coor[0]])
			put_sprite_line(m_coor, sprite, main_img, tex_img);
		m_coor[0]++;
	}
	return (sprite);
}

t_sprites	*sprite_height_width(t_sprites *sprite_list)
{
	sprite_list->screenx = (int)((g_screenwidth / 2)
			* (1 + sprite_list->transformx / sprite_list->transformy));
	sprite_list->spriteheight = abs((int)(g_screenheight /
		(sprite_list->transformy)));
	sprite_list->drawstarty = -sprite_list->spriteheight
		/ 2 + g_screenheight / 2;
	if (sprite_list->drawstarty < 0)
		sprite_list->drawstarty = 0;
	sprite_list->drawendy = sprite_list->spriteheight /
		2 + g_screenheight / 2;
	if (sprite_list->drawendy >= g_screenheight)
		sprite_list->drawendy = g_screenheight - 1;
	sprite_list->spritewidth = abs((int)(g_screenheight /
		(sprite_list->transformy)));
	sprite_list->drawstartx = -sprite_list->spritewidth /
		2 + sprite_list->screenx;
	if (sprite_list->drawstartx < 0)
		sprite_list->drawstartx = 0;
	sprite_list->drawendx = sprite_list->spritewidth /
		2 + sprite_list->screenx;
	if (sprite_list->drawendx >= g_screenwidth)
		sprite_list->drawendx = g_screenwidth - 1;
	return (sprite_list);
}

t_sprites	*put_sprites(t_vars *vars, t_sprites *sprite_list,
		t_data *g_tex_list, t_data *main_img)
{
	t_fov	fov;

	fov = vars->fov;
	while (sprite_list != NULL)
	{
		sprite_list->spritex = sprite_list->x - fov.posx;
		sprite_list->spritey = sprite_list->y - fov.posy;
		sprite_list->invdet = 1.0
			/ (fov.planex * fov.diry - fov.dirx * fov.planey);
		sprite_list->transformx = sprite_list->invdet * (fov.diry
			* sprite_list->spritex - fov.dirx * sprite_list->spritey);
		sprite_list->transformy = sprite_list->invdet * (-fov.planey
			* sprite_list->spritex + fov.planex * sprite_list->spritey);
		sprite_height_width(sprite_list);
		sprite_on_screen(sprite_list, g_tex_list, main_img);
		sprite_list = sprite_list->next;
	}
	return (sprite_list);
}
