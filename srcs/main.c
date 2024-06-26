# include "../includes/cub.h"

int	do_frame(t_data *data)
{
	t_image	win_img;
	win_img = image_new(data->mlx, screenWidth, screenHeight);
    handle_keypress(data);
	main_raycast(data, win_img);
	//display_minimap(data);
    mlx_put_image_to_window(data->mlx, data->win, win_img.img, 0, 0);
	image_delete(data->mlx, win_img);
	return (0);
}


int	main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		printf("pk tu veux casser mon cuuuuuuuub");
		return (1);
	}
	data.posX = 12;
	data.posY = 5;
	data.player_start_dir = 'N';
	init_player_direction(&data);
	data.moveSpeed = 0.01;
	data.rotSpeed = 0.01;
	
	init_keys(&data);
	data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "mlx");
	//init_minimap(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);

	mlx_loop(data.mlx);
}