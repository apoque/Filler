/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:51:03 by apoque            #+#    #+#             */
/*   Updated: 2018/04/03 16:38:01 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include <stdlib.h>
# include "libft/libft.h"
typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_filler
{
	char			**tab;
	int				**nb;
	t_coor			*targets;
	t_coor			*spots;
	int				nb_targets;
	int				nb_spots;
	t_coor			size;
	short			player;
	short			enemi;
	t_coor			piece_size;
	char			**piece;
	t_coor			*piece_coor;
	short			piece_width;
	short			piece_height;
	short			ok;
	t_coor			output;
}					t_filler;

char				*ft_treat_tab(char *line);
void				ft_treat_piece(t_filler *fil);
void				ft_free_struct(t_filler fil);
void				ft_algo(t_filler *fil);
void				ft_spot_clear(t_filler *fil, int i, int j);
int					ft_get_dist(t_filler *fil, int k, int i);
void				ft_get_piece_coor(t_filler *fil);
void				ft_place_piece(t_filler *fil);
int					ft_power(int nb, int power);
int					ft_check_place(t_filler *fil, int k, int i);
void				ft_try_else(t_filler *fil);
#endif
