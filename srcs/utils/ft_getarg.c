/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:31:50 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/29 18:36:29 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

int	ft_getarg(const char *format, va_list *ap, t_arg *arg)
{
	size_t				i;
	const char			*char_type = "cdiuxXsp%";
	const t_arg_type	*types = (t_arg_type []){\
	CHAR, INT, INT, UINT, HEX, HEX_UP, STRING, PTR, PERCENT};

	if (!*format)
		return (1);
	i = ft_strchr(char_type, *format) - char_type;
	if (i > PERCENT)
	{
		arg->arg = (void *)('%');
		return (1);
	}
	else
		arg->type = types[i];
	if (arg->type < UINT)
		arg->arg = (void *)(long)va_arg(*ap, int);
	else if (arg->type < STRING)
		arg->arg = (void *)(long)va_arg(*ap, unsigned int);
	else if (arg->type < PERCENT)
		arg->arg = va_arg(*ap, void *);
	else
		arg->arg = (void *)('%');
	return (0);
}
