/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:48:38 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/03 12:24:24 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*read_two(t_fdf *fdf, char *buf, char *tmp, char *line)
{
	if (!(ft_isdigit(*line) || *line == ',' || *line == 'x' \
	|| *line == ' ' || *line == '\n' || *line == '-'))
	{
		line++;
		return (0);
	}
	if (fdf->map.width == ft_count_words(line, ' ') || fdf->map.height == 1)
		fdf->map.width = ft_count_words(line, ' ');
	else
	{
		ft_putstr("No no no, my sweet, give me valid file");
		exit(0);
	}
	tmp = ft_strjoin(buf, line);
	free(buf);
	free(line);
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	return (buf);
}

int		*fdf_reader(char *argv, t_fdf *fdf)
{
	char	*line;
	char	*buf;
	char	**map;
	char	*tmp;
	int		fd;

	tmp = NULL;
	fdf->map.height = 0;
	fdf->map.width = 0;
	buf = ft_strdup("\0");
	if (((fd = open(argv, O_RDONLY)) < 0))
		ft_putstr("error");
	while (((get_next_line(fd, &line)) > 0) && ++fdf->map.height)
		buf = read_two(fdf, buf, tmp, line);
	if (!fdf->map.width)
	{
		ft_putstr("Error");
		exit(0);
	}
	close(fd);
	map = ft_strsplit(buf, '\n');
	free(buf);
	map_in_int(map, fdf);
	close(fd);
	return (0);
}

void	map_in_int(char **map, t_fdf *fdf)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	fdf->map.values = (int**)malloc(sizeof(int*) * fdf->map.height);
	while (y < fdf->map.height)
	{
		fdf->map.values[y] = (int*)malloc(sizeof(int) * fdf->map.width);
		tmp = ft_strsplit(map[y], ' ');
		free(map[y]);
		x = 0;
		while (x < fdf->map.width)
		{
			fdf->map.values[y][x] = atoi(tmp[x]);
			free(tmp[x]);
			x++;
		}
		free(tmp);
		y++;
	}
	free(map);
}
