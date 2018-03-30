/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:51:03 by apoque            #+#    #+#             */
/*   Updated: 2018/03/19 16:29:14 by apoque           ###   ########.fr       */
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
	t_coor			size;
	short			player;
	t_coor			piece_size;
	char			**piece;
	short			piece_width;
	short			piece_height;
	short			ok;
	t_coor			output;
}					t_filler;

void				ft_treat_piece(t_filler *fil);
void				ft_free_struct(t_filler *fil);
void				ft_algo(t_filler *fil);

#endif
