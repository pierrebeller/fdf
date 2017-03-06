/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:00:51 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:00:58 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx_macos/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "fdf.h"
#include "./gnl/get_next_line.h"

void		printer(t_list *map)
{
	t_points	*points;

	points = (t_points *)map->content;
	printf("%d\n", points->x);
	printf("%d\n", points->y);
	printf("%d\n\n", points->z);
}


t_points	*new_point(int x, int y, char *z)
{
	t_points	*points;

	points = malloc(sizeof(t_points));
	points->x = x;
	points->y = y;
	points->z = ft_atoi(z);
	return (points);
}

int		spliter(char *line, int y)
{
	int 		i;
	char 		**tab;
	t_list		*map;

	i = 0;
	map = NULL;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		{
			ft_lst_push_back(&map, ft_lstnew(new_point(i, y, tab[i]), sizeof(t_points*)));
			printf("%s\n", tab[i]);
			free(tab[i]);
			i++;
		}
	free(line);
	free(tab);
	ft_lstiter(map, &printer);
	return (0);
}

int		main(int argc, char **argv)
{
	//void	*mlx;
	//void	*win;
	int		fd;
	int		y;
	char	*line;

	line = ft_strdup("");
	y = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		spliter(line, y);
		y++;
	}

	/*mlx = mlx_init();
	win = mlx_new_window(mlx, 256, 256, "window test");
	mlx_pixel_put(mlx, win, 128, 128, 0x00FFFFFF);
	mlx_loop(mlx);*/
	return (0);
}

/*
gnl ==> str
split /s chaque ligne ==> tableau des abcisses de chaque ligne
atoi 
liste chainee  */

