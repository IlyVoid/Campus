#include "../include/fdf.h"

void	scroll_hook(double a, double scroll, void	*param)
{
	t_FdF	*s;

	s = param;
	if (a || mlx_is_key_down(s->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(s->mlx, MLX_KEY_RIGHT_SHIFT))
	{
}
