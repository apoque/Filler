/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:13:17 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 20:40:22 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

#include <stdio.h>
#include <unistd.h>

#define Y fil->size.y
#define X fil->size.x
#define I fil->piece_size.x
#define J fil->piece_size.y

int		ft_get_piece(t_filler *fil, char *line)
{
	int		i;

	i = 0;
	dprintf(2, "GET_PIECE\n\nline = |%s|\n\nPIECE\n\n", line);
	while (!(ft_isdigit(line[i])))
		i++;
	fil->piece_size.y = ft_atoi(&(line[i]));
	while (ft_isdigit(line[i]))
		i++;
	fil->piece_size.x = ft_atoi(&(line[i]));
	i = 0;
	fil->piece = (char **)malloc(sizeof(char *) * (fil->piece_size.y + 1));

	//dprintf(2, "fil pieces : %p\n", fil->piece);
	while (i < fil->piece_size.y)
	{
		//fil->piece[i] = ft_strnew(sizeof(char) * I);
		if (get_next_line(0, &(fil->piece[i])) < 0)
			return (0);
		//fil->piece[i][I] = '\0';
		dprintf(2, "%s\n", fil->piece[i]);
		//dprintf(2, "les fil pieces[i] : %p\n", fil->piece[i]);
		i++;
	}
	fil->piece[fil->piece_size.y] = NULL;


	fil->piece_coor = (t_coor *)malloc(sizeof(t_coor) * I * J);
	//dprintf(2, "pieces coor : %p\n", fil->piece_coor);
	i = 0;
	while (i <= I * J)
	{
		dprintf(2, "%s\n", fil->piece[0]);
		fil->piece_coor[i].x = -1;
		fil->piece_coor[i].y = -1;
		i++;
	}
	//printf("\n<%s>\n", line);
	//if (line)
	//	free(line);
	dprintf(2, "piece x = %i y = %i\n", fil->piece_size.x, fil->piece_size.y);
	i = 0;
	/*dprintf(2, "LA PIECE\n");
	while (i < J)
	{
		dprintf(2, "%s\n", fil->piece[i]);
		i++;
	}*/
	//ft_treat_piece(fil);

	return (1);
}

int		ft_init_plate(t_filler *fil)
{
	int	i;
	int	j;

	i = 0;
	//if (fil->tab)
	//	free(fil->tab);
	fil->tab = (char **)malloc(sizeof(char *) * Y);
	//dprintf(2, "fil tab : %p\n", fil->tab);
	/*while (i < Y)
	{
		fil->tab[i] = ft_strnew(X);
		dprintf(2, "les fil tab[i] : %p\n", fil->nb);
		//fil->tab[i] = (char *)malloc(sizeof(char) * (X + 1));
		i++;
	}*/
	i = 0;
	fil->nb = (int **)malloc(sizeof(int *) * Y);
	//dprintf(2, "fil nb : %p\n", fil->nb);
	while (i < Y)
	{
		j = 0;
		fil->nb[i] = (int *)malloc(sizeof(int) * X);
		//dprintf(2, "les fil nb[i] : %p\n", fil->nb[i]);
		while (j < X)
		{
			fil->nb[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_treat_tab(char *line)
{
	char *tmp;

	tmp = ft_strdup(line + 4);
	free(line);
	line = ft_strdup(tmp);
	free(tmp);
	return (line);
}

int		ft_get_plate(t_filler *fil)
{
	//char	**tab;
	//char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	//tab = (char **)malloc(sizeof(char *) * (Y + 1));
	//dprintf(2, "tab : %p\n", tab);
	while (i <= Y)
	{
		if (get_next_line(0, &fil->tab[k]) < 0)
			return (0);
		fil->tab[k] = ft_treat_tab(fil->tab[k]);
		//dprintf(2, "line : %p\n", fil->tab[k]);
		if (i > 0)
		{
			j = 0;
			//fil->tab[k] = ft_strdup(tab[i] + 4);
			//fil->tab[k][X] = '\0';
			//fil->tab[k] = ft_strdup(line + 4);
			//fil->tab[k][X] = '\0';
			while (j < X && k < Y)
			{
				//fil->tab[k][j] = tab[i][j + 4];
				if (fil->tab[k][j] == 'o' || fil->tab[k][j] == 'O')
					fil->nb[k][j] = 1;
				else if (fil->tab[k][j] == 'x' || fil->tab[k][j] == 'X')
					fil->nb[k][j] = 2;
				j++;
			}
			k++;
		}
		//free(line);
		i++;
	}
	//tab[Y + 1] = NULL;
	i = 0;
	//printf("%s\nTABLEAU\n", tab[Y]);
	while (i < Y)
	{
		//if (i < Y)
			//dprintf(2, "%s\n", fil->tab[i]);
		//if (tab[i])
		{
			//dprintf(2, "OUF%p\n",  tab[i]);
			//dprintf(2, "tab[i] : %p\n", tab[i]);
			//free(tab[i]);
		}
		i++;
	}
	//dprintf(2, "tab : %p\n", tab);
	//if (tab)
	//	free(tab);
	return (1);
}

int		ft_get_plate_size(t_filler *fil, char *line)
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
	//if (fil->targets)
	//	free(fil->targets);
	fil->targets = (t_coor *)malloc(sizeof(t_coor) * X * Y - 1);
	//dprintf(2, "fil targets : %p\n", fil->targets);
	//if (fil->spots)
	//	free(fil->spots);
	fil->spots = (t_coor *)malloc(sizeof(t_coor) * X * Y - 1);
	//dprintf(2, "fil spots : %p\n", fil->spots);
	i = 0;
	while (i < X * Y)
	{
		fil->targets[i].x = -1;
		fil->targets[i].y = -1;
		fil->spots[i].x = -1;
		fil->spots[i].y = -1;
		i++;
	}
	//if (line)
	//	free(line);
	//printf("x = %i y = %i\n", X, Y);
	return (1);
}

int		main(void)
{
	t_filler	fil;
	short		flag;
	//char		*line1;
	char		*line2;

	ft_bzero(&fil, sizeof(fil));
	fil.ok = 1;
	line2 = "";
	get_next_line(0, &line2);
	fil.player = (((!(ft_strstr(line2, "apoque.filler") == NULL)) && (!((ft_strstr(line2, "p1")) == NULL))) ? 1 : 2);
	fil.enemi = ((fil.player == 1) ? 2 : 1);
	//printf("%s\n", line2);
	//dprintf(2, "apoque = %i enemi = %i\n", fil.player, fil.enemi);
	if (line2)
		//free(line2);
	while (fil.ok == 1)
	{
		dprintf(2, "__1__\n");
		flag = 0;
		if (fil.ok == 0 || (get_next_line(0, &line2) <= 0))
			break;
		//printf("%s\nYO\n", line);
		//if (!line)
		//	continue;
		dprintf(2, "__2__\n");
		if (!(ft_strstr(line2, "Plateau") == NULL))
		{
			dprintf(2, "__3__\n");
			ft_get_plate_size(&fil, line2);
			dprintf(2, "__4__\n");
			ft_init_plate(&fil);
			dprintf(2, "__5__\n");
			ft_get_plate(&fil);
			dprintf(2, "__6__\n");
		}
		else if (!(ft_strstr(line2, "Piece") == NULL))
		{
			dprintf(2, "__7__\n");
			ft_get_piece(&fil, line2);
			dprintf(2, "__8__\n");
			ft_algo(&fil);
			dprintf(2, "__9__\n");
			dprintf(1, "%i %i\n", fil.output.y, fil.output.x);
			dprintf(2, "__10__\n");
			flag = 1;
		}
		dprintf(2, "__11__\n");
		//if (line)
		//	free(line);
		//if (flag == 1)
		//	ft_free_struct(&fil);
	}
	//	while (1)
	//		;
	//if (fil.ok == 0)
	//	ft_free_struct(&fil);
	//while (1)
	//	;
	return (0);
}
