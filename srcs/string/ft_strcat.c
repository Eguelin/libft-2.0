/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:58:17 by eguelin           #+#    #+#             */
/*   Updated: 2025/03/05 18:40:06 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dst, const char *restrict src)
{
	char	*ret;

	ret = dst;
	while (*dst)
		dst++;
	ft_strcpy(dst, src);
	return (ret);
}
