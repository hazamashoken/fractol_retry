/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:16:25 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/10 00:16:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	val;

	if (*nptr == '\0')
		return (0);
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == 32)
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	val = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		val = (val * 10) + (*nptr - 48);
		nptr++;
	}
	return (sign * val);
}
