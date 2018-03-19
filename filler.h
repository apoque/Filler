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
	t_coor			size;
	short			player;
}					t_filler;

#endif
