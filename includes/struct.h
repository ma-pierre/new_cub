/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:05:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/03/20 16:20:29 by mapierre         ###   ########.fr       */
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

	t_key   keys;
	void	*mlx;
	void	*win;
}				t_data;

#endif