#include "../includes/cub.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == 's')
        data->keys.s = 1;
    if (keycode == 'd')
        data->keys.d = 1;
    if (keycode == 'a')
        data->keys.a = 1;
    if (keycode == 'w')
        data->keys.w = 1;
    if (keycode == 65307)
        data->keys.esc = 1;
    if (keycode == 65361)
        data->keys.l_arrow = 1;
    if (keycode == 65363)
        data->keys.r_arrow = 1;
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == 's')
        data->keys.s = 0;
    if (keycode == 'd')
        data->keys.d = 0;
    if (keycode == 'a')
        data->keys.a = 0;
    if (keycode == 'w')
        data->keys.w = 0;
    if (keycode == 65307)
        data->keys.esc = 0;
    if (keycode == 65361)
        data->keys.l_arrow = 0;
    if (keycode == 65363)
        data->keys.r_arrow = 0;
    return (0);
}

int	handle_keypress(t_data *data)
{
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_back(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.r_arrow)
		camera_right(data);
    if (data->keys.l_arrow)
		camera_left(data);
	if (data->keys.esc)
    {
		exit(0);
        //MLXLOOPEND?????????
    }
	//calc(data);

	return (0);
}