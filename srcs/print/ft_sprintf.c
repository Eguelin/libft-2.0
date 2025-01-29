/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:38:18 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <limits.h>

int	ft_sprintf(char *str, const char *format, ...)
{
	t_printf	pf;

	ft_init_pf(&pf, 1, str, ULONG_MAX);
	pf.ft_write_pf = &ft_write_pf;
	va_start(pf.ap, format);
	if (ft_print_loop(format, &pf))
		return (-1);
	if (ft_write_pf(&pf) == -1)
		return (-1);
	va_end(pf.ap);
	return (pf.ret);
}
