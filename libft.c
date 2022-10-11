/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:12:49 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/10 00:16:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len) != '\0')
		len++;
	return (len);
}

int	ft_putstr_fd(char *str, int fd)
{
	if (fd < 0 || !str)
		return (0);
	return (write(fd, str, ft_strlen(str)));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = (char)(c);
	return (s);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*ptr;

	if (nmeb * size + 1 > SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(nmeb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmeb * size);
	return (ptr);
}
