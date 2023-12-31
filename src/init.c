/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:19:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/09/30 15:05:17 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_mlx(t_window *window)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (MLX_ERROR);
	window->win_ptr
		= mlx_new_window(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fract'ol");
	if (!window->win_ptr)
	{
		free(window->mlx_ptr);
		return (MLX_ERROR);
	}
	window->img.mlx_img = mlx_new_image(window->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!window->img.mlx_img)
		return (MLX_ERROR);
	window->img.addr = mlx_get_data_addr
		(window->img.mlx_img, &(window->img.bpp),
			&(window->img.line_len), &(window->img.endian));
	if (!window->img.addr)
		return (MLX_ERROR);
	return (0);
}

t_window	*init_window(void)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
		return (0x0);
	window->mlx_ptr = 0x0;
	ft_bzero(&(window->img), sizeof(t_img));
	window->win_ptr = 0x0;
	window->set = 0;
	window->julia_cmplx = 0x0;
	window->color = 0;
	window->zoom = 0.99;
	window->offset.x = 0;
	window->offset.y = 0;
	return (window);
}
