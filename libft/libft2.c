/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:16:25 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/16 11:58:44 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

double	ft_add_decimal(const char *nptr, double sign, double val)
{
	double	val2;
	double	len;

	len = 0;
	val2 = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		val2 = (val2 * 10) + (*nptr - 48);
		nptr++;
		len++;
	}
	while (len--)
	{
		val2 /= 10.0;
	}
	return (sign * (val + val2));
}

double	ft_atoi(const char *nptr)
{
	double	sign;
	double	val;

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
	if (*nptr == '.')
		return (ft_add_decimal(++nptr, sign, val));
	return (sign * val);
}
