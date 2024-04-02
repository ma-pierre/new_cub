/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:56:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/02 03:48:12 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"


int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
							{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
							{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

//pour verline, peu etre je peu reduire le nb d'arg en creant les int dans ma struct???)
//A MODIFIER POUR TEXTURES CA SERT PLUS

void	verLine(t_image image, int x, int y1, int y2, int color)
{
	while (y1 <= y2)
	{
		image_put_px(image, x, y1, color);
		y1++;
	}
}

void    raycast_init_var(t_data *data, int x)
{
    data->raycast_var.cameraX = 2 * x / (double)width - 1;
    data->raycast_var.rayDirX = data->dirX + data->planeX * data->raycast_var.cameraX;
    data->raycast_var.rayDirY = data->dirY + data->planeY * data->raycast_var.cameraX;
    data->raycast_var.mapX = (int)data->posX;
    data->raycast_var.mapY = (int)data->posY;
    data->raycast_var.sideDistX = 0;
    data->raycast_var.sideDistY = 0;
    data->raycast_var.deltaDistX = fabs(1 / data->raycast_var.rayDirX);
    data->raycast_var.deltaDistY = fabs(1 / data->raycast_var.rayDirY);
    data->raycast_var.perpWallDist = 0;
    data->raycast_var.stepX = 0;
    data->raycast_var.stepY = 0;
}

void    raycast_init_raydir(t_data *data)
{       
    if (data->raycast_var.rayDirX < 0)
    {
		data->raycast_var.stepX = -1;
		data->raycast_var.sideDistX = (data->posX - data->raycast_var.mapX) * data->raycast_var.deltaDistX;
	}
	else
	{
		data->raycast_var.stepX = 1;
		data->raycast_var.sideDistX = (data->raycast_var.mapX + 1.0 - data->posX) * data->raycast_var.deltaDistX;
	}
	if (data->raycast_var.rayDirY < 0)
	{
		data->raycast_var.stepY = -1;
		data->raycast_var.sideDistY = (data->posY - data->raycast_var.mapY) * data->raycast_var.deltaDistY;
	}
	else
	{
		data->raycast_var.stepY = 1;
        data->raycast_var.sideDistY = (data->raycast_var.mapY + 1.0 - data->posY) * data->raycast_var.deltaDistY;
	}
}

int		raycast_dda(t_data *data)
{
		int	i;
		int	side;

		i = 0;
		while (i == 0)
		{
			if (data->raycast_var.sideDistX < data->raycast_var.sideDistY)
			{
				data->raycast_var.sideDistX += data->raycast_var.deltaDistX;
				data->raycast_var.mapX += data->raycast_var.stepX;
				side = 0;
			}
			else
			{
				data->raycast_var.sideDistY += data->raycast_var.deltaDistY;
				data->raycast_var.mapY += data->raycast_var.stepY;
				side = 1;
			}
			if (worldMap[data->raycast_var.mapX][data->raycast_var.mapY] > 0) i = 1;
		}
		return (side);
}

void	main_raycast(t_data *data, t_image win_img)
{
	int	x;
	int side; 

	x = 0;
	while (x < width)
	{
		raycast_init_var(data, x);
		raycast_init_raydir(data);
		side = raycast_dda(data);
		if (side == 0)
			data->raycast_var.perpWallDist = (data->raycast_var.mapX - data->posX + (1 - data->raycast_var.stepX) / 2) / data->raycast_var.rayDirX;
		else
			data->raycast_var.perpWallDist = (data->raycast_var.mapY - data->posY + (1 - data->raycast_var.stepY) / 2) / data->raycast_var.rayDirY;
			
		int lineHeight = (int)(height / data->raycast_var.perpWallDist);

		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		int	color;
		color = 0xffc3f8; 
		if (side == 0)
		{ // Mur vertical
        	if (data->raycast_var.stepX > 0)
            	color = 0xFFC0CB; // Est - Rose
        	else
            	color = 0x0000FF; // Ouest - Bleu
    	} 
		else
		{ // Mur horizontal
        if (data->raycast_var.stepY > 0)
            color = 0xFF0000; // Sud - Rouge
        else
            color = 0x000000; // Nord - Noir
    	}

		verLine(win_img, x, 0, drawStart, 0xffdfdf);
		verLine(win_img, x, drawStart, drawEnd, color);
		verLine(win_img, x, drawEnd, height, 0xae84a9);
		x++;
	}
}