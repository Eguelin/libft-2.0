/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:01:56 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/30 15:20:36 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char *start;
	size_t		*qword_ptr;
	size_t		qword;
	size_t		i;

	start = s;
	i = (size_t)s % sizeof(size_t);
	while (i > 0)
	{
		if (*s == 0)
			return (s - start);
		s++;
		i--;
	}
	qword_ptr = (size_t *)s;
	qword = *qword_ptr;
	while (!((qword - 0x0101010101010101) & ~qword & 0x8080808080808080))
	{
		qword_ptr++;
		qword = *qword_ptr;
	}
	s = (char *)qword_ptr;
	while (*s)
		s++;
	return (s - start);
}
