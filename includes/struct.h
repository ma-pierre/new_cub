/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:05:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/03/31 23:20:35 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define	STRUCT_H

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_key
{
    int     s;
    int     w;
    int     d;
    int     a;
	int     esc;
    int     l_arrow;
    int     r_arrow;
}   			t_key;

typedef	struct s_raycast
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
//	int		hit;
//	int		side;
}				t_raycast;

typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;
	char	*textures[4];
	char	player_start_dir;
	t_key   keys;
	void	*mlx;
	void	*win;
	t_raycast	raycast_var;
}				t_data;

/*
typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;
	char	player_start_dir;
	    void    *minimap_img;  // Image de la minimap
    char    *minimap_addr;
	 int     bits_per_pixel;
    int     line_length;
    int     endian;

	t_key   keys;
	void	*mlx;
	void	*win;
}				t_data;
*/

#endif