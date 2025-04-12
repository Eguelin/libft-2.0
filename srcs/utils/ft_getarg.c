/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:31:50 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 14:27:31 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_getarg(va_list *ap, t_arg *arg)
{
	if (arg->type < UINT)
		arg->value = (void *)(long)va_arg(*ap, int);
	else if (arg->type < STRING)
		arg->value = (void *)(long)va_arg(*ap, unsigned int);
	else if (arg->type < PERCENT)
		arg->value = va_arg(*ap, void *);
	else
		arg->value = (void *)('%');
	return (0);
}
