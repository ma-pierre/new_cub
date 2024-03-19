#include "cub.h"

void    camera_left(t_info *info)
{
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = info->dirX;
    current_PlaneX = info->planeX;
	info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
	info->dirY = current_DirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
	info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
	info->planeY = current_PlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
}

void    camera_right(t_info *info)
{	    
    double current_DirX;
    double current_PlaneX;
    
    current_DirX = info->dirX;
    current_PlaneX = info->planeX;
	info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
	info->dirY = current_DirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
	info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
	info->planeY = current_PlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
}