#include "cub.h"

void    move_forward(t_info *info)
{
    if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
}

void    move_back(t_info *info)
{
    if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
	if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
}

void move_left(t_info *info)
{
    double  perpDirX;
    double  perpDirY;

    perpDirX = info->dirY;
    perpDirY = -info->dirX;   
    if (!worldMap[(int)(info->posX + perpDirX * info->moveSpeed)][(int)(info->posY)])
        info->posX += perpDirX * info->moveSpeed;
    if (!worldMap[(int)(info->posX)][(int)(info->posY + perpDirY * info->moveSpeed)])
        info->posY += perpDirY * info->moveSpeed;
}

void move_right(t_info *info)
{
    double  perpDirX;
    double  perpDirY;
    
    perpDirX = -info->dirY;
    perpDirY = info->dirX;
    if (!worldMap[(int)(info->posX + perpDirX * info->moveSpeed)][(int)(info->posY)])
        info->posX += perpDirX * info->moveSpeed;
    if (!worldMap[(int)(info->posX)][(int)(info->posY + perpDirY * info->moveSpeed)])
        info->posY += perpDirY * info->moveSpeed;
}