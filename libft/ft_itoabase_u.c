/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:07:56 by apoque            #+#    #+#             */
/*   Updated: 2018/03/13 16:08:03 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(uintmax_t value, char *base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		i++;
		value = value / ft_strlen(base);
	}
	return (i);
}

static void	ft_fillitoa(char *str, uintmax_t l, char *base)
{
	int i;
	int k;

	i = 0;
	k = ft_countdigits(l, base);
	while (l > 0)
	{
		str[i] = base[l % ft_strlen(base)];
		l = l / ft_strlen(base);
		i++;
	}
}

char		*ft_itoabase_u(uintmax_t value, char *base)
{
	int		k;
	char	*str;

	if (value == 0)
		return (ft_strdup("0"));
	k = ft_countdigits(value, base);
	if (!(str = ft_strnew(k)))
		return (0);
	str[k] = '\0';
	ft_fillitoa(str, value, base);
	return (ft_strrev(str));
}
