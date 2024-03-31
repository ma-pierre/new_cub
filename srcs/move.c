/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:35 by mapierre          #+#    #+#             */
/*   Updated: 2024/03/30 18:21:21 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub.h"

void    move_forward(t_data *data)
{
    if (!worldMap[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX += data->dirX * data->moveSpeed;
	if (!worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)])
			data->posY += data->dirY * data->moveSpeed;
}

void    move_back(t_data *data)
{
    if (!worldMap[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX -= data->dirX * data->moveSpeed;
	if (!worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)])
			data->posY -= data->dirY * data->moveSpeed;
}

void move_left(t_data *data)
{
    double  perpDirX;
    double  perpDirY;

    perpDirX = data->dirY;
    perpDirY = -data->dirX;   
    if (!worldMap[(int)(data->posX + perpDirX * data->moveSpeed)][(int)(data->posY)])
        data->posX += perpDirX * data->moveSpeed;
    if (!worldMap[(int)(data->posX)][(int)(data->posY + perpDirY * data->moveSpeed)])
        data->posY += perpDirY * data->moveSpeed;
}

void move_right(t_data *data)
{
    double  perpDirX;
    double  perpDirY;
    
    perpDirX = -data->dirY;
    perpDirY = data->dirX;
    if (!worldMap[(int)(data->posX + perpDirX * data->moveSpeed)][(int)(data->posY)])
        data->posX += perpDirX * data->moveSpeed;
    if (!worldMap[(int)(data->posX)][(int)(data->posY + perpDirY * data->moveSpeed)])
        data->posY += perpDirY * data->moveSpeed;
}