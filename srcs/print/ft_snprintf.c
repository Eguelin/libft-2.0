/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:38:18 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/12 14:24:42 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list		ap;
	t_printf	pf;
	t_format	ft;
	t_string	t_str;

	ft_init_t_string(&t_str, str, size);
	ft_init_t_printf(&pf, -1, &ft_flush_buff, &t_str);
	ft_init_t_format(&ft, format);
	va_start(ap, format);
	if (ft_print_loop(&ft, &pf, &ap))
		pf.ret = -1;
	pf.flush(&pf);
	va_end(ap);
	return (pf.ret);
}
