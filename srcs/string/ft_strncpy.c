/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:10:34 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 12:15:35 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	while (dsize < i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (dsize < i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
