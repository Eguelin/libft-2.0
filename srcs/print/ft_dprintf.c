/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:38:18 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/12 14:37:49 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_printf	pf;
	t_format	ft;

	ft_init_t_printf(&pf, fd, &ft_write_pf, NULL);
	ft_init_t_format(&ft, format);
	va_start(ap, format);
	if (ft_print_loop(&ft, &pf, &ap))
		pf.ret = -1;
	if (pf.ret != -1 && pf.flush(&pf) == -1)
		pf.ret = -1;
	va_end(ap);
	return (pf.ret);
}
