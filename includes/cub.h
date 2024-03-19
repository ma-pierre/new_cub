#include <stdlib.h>
#include <string.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"
#include "math.h"
#include <stdio.h>

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

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

//MOVE_CAMERA.c
void    camera_left(t_info *info);
void    camera_right(t_info *info);
//MOVE.c
void    move_forward(t_info *info);
void    move_back(t_info *info);
void    move_left(t_info *info);
void    move_right(t_info *info);

extern int worldMap[24][24];
