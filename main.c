/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 19:13:54 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

#include <stdio.h>
#include <unistd.h>

#define Y fil->size.y
#define X fil->size.x

void	ft_get_piece(t_filler *fil)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	while (!(ft_isdigit(*line)))
		line++;
	fil->piece_size.y = ft_atoi(&(*line));
	line++;
	fil->piece_size.x = ft_atoi(&(*line));
	i = 0;
	fil->piece = (char **)malloc(sizeof(char *) * (fil->piece_size.y + 1));
	while (i < fil->piece_size.y)
	{
		get_next_line(0, &(fil->piece[i]));
		i++;
	}
	fil->piece[i] = NULL;
	ft_treat_piece(fil);
}

void	ft_init_plate(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	fil->tab = (char **)malloc(sizeof(char *) * (Y + 1));
	fil->tab[Y] = NULL;
	while (i < Y)
	{
		fil->tab[i] = (char *)malloc(sizeof(char) * (X + 1));
		fil->tab[i][X] = '\0';
		i++;
	}
	i = 0;
	fil->nb = (int **)malloc(sizeof(int *) * Y);
	while (i < Y)
	{
		j = 0;
		fil->nb[i] = (int *)malloc(sizeof(int) * X);
		while (j < X)
		{
			fil->nb[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_get_plate(t_filler *fil)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (Y + 2));
	while (i <= Y)
	{
		get_next_line(0, &tab[i]);
		if (ft_isdigit(tab[i][0]))
		{
			j = 0;
			while (j <= X)
			{
				fil->tab[k][j] = tab[i][j + 4];
				if (fil->tab[k][j] == 'o' || fil->tab[k][j] == 'O')
					fil->nb[k][j] = 1;
				else if (fil->tab[k][j] == 'x' || fil->tab[k][j] == 'X')
					fil->nb[k][j] = 2;
				j++;
			}
			k++;
		}
		i++;
	}
	fil->tab[i] = NULL;
	free(tab);
}

void	ft_get_plate_size(t_filler *fil, char *line)
{
	int		i;

	i = 0;
	fil->output.x = 0;
	fil->output.y = 0;
	while (!ft_isdigit(line[i]))
		i++;
	Y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i++;
	X = ft_atoi(&line[i]);
	//free(line);
}

int		main(void)
{
	t_filler	fil;
	char		*line;

	ft_bzero(&fil, sizeof(fil));
	fil.ok = 1;
	line = "";
	while (ft_strstr(line, "Plateau") == NULL)
	{
		get_next_line(0, &line);
		if (ft_strstr(line, "apoque") != NULL)
		{
			if (ft_strstr(line, "1") != NULL)
				fil.player = 1;
			else if (ft_strstr(line, "2") != NULL)
				fil.player = 2;
		}
	}

	while (fil.ok == 1)
	{
		ft_get_plate_size(&fil, line);
		ft_init_plate(&fil);
		ft_get_plate(&fil);
		ft_get_piece(&fil);
		ft_algo(&fil);
		//printf("game x = %i y = %i\npiece x = %i y = %i\nouput x = %i y = %i\n", fil.size.x, fil.size.y, fil.piece_size.x, fil.piece_size.y, fil.output.x, fil.output.y);
		ft_free_struct(&fil);
	}
	return (0);
}
