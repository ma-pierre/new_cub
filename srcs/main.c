# include "../includes/cub.h"

int	do_frame(t_data *data)
{
    handle_keypress(data);
	calc(data);
	// mlx_put_image_to_window(data->mlx, data->win, &data->img, 0, 0);//pour les textures
    
	return (0);
}

int	main(void)
{
	t_data data;
    
	data.mlx = mlx_init();

	data.posX = 12;
	data.posY = 5;
	data.dirX = -1;
	data.dirY = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.moveSpeed = 0.05;
	data.rotSpeed = 0.05;
	
	data.win = mlx_new_window(data.mlx, width, height, "mlx");
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);

	mlx_loop(data.mlx);
}