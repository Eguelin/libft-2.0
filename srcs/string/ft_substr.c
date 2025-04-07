/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:26:11 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/04 12:02:52 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || start > ft_strlen(s) || len == 0)
		return (NULL);
	s += start;
	sub = malloc(len);
	if (!sub)
		return (NULL);
	ft_strncpy(sub, s, len);

}
