/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:04:58 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/02 01:54:26 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define	CUB_H

#include <stdlib.h>
#include <string.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
#include "math.h"
#include <stdio.h>
#include "struct.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480

#define KeyPressMask			(1L<<0)
#define KeyReleaseMask			(1L<<1)
#define KeyPress	2
#define KeyRelease 3
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480


//MOVE_CAMERA.c
void    camera_left(t_data *data);
void    camera_right(t_data *data);
//MOVE.c
void    move_forward(t_data *data);
void    move_back(t_data *data);
void    move_left(t_data *data);
void    move_right(t_data *data);
//HANDLE_KEY_PRESS
void    init_keys(t_data *data);
int     key_press(int keycode, t_data *data);
int     key_release(int keycode, t_data *data);
int     handle_keypress(t_data *data);
//RAYCASTING
void	main_raycast(t_data *data, t_image win_img);
void	verLine(t_image image, int x, int y1, int y2, int color);
void    raycast_init_var(t_data *data, int x);
void    raycast_init_raydir(t_data *data);
int		raycast_dda(t_data *data);

//
int     do_frame(t_data *data);
void    init_player_direction(t_data *data);

void    clean_game(t_data *data);

///img
t_image	image_new(void *mlx, size_t w, size_t h);
void	image_put_px(t_image img, int x, int y, int color);
void	image_delete(void	*mlx, t_image img);

// MINIMAP 
void init_minimap(t_data *data);
void draw_minimap(t_data *data);
void update_player_position_on_minimap(t_data *data);
void display_minimap(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

extern int worldMap[24][24];

#endif