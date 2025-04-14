/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:43:51 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 18:11:49 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*p;

	p = ft_strnstr(haystack, needle, LONG_MAX);
	return (p);
}
