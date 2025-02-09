/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:10:34 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/30 14:50:21 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n < i && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (n < i && src[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
