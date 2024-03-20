/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:41 by mapierre          #+#    #+#             */
/*   Updated: 2024/03/20 15:03:34 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

void    camera_left(t_data *data)
{
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = data->dirX;
    current_PlaneX = data->planeX;
	data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
	data->dirY = current_DirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
	data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
	data->planeY = current_PlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
}

void    camera_right(t_data *data)
{	    
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = data->dirX;
    current_PlaneX = data->planeX;
	data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
	data->dirY = current_DirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
	data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
	data->planeY = current_PlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
}