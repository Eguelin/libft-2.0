/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:52:55 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_print_loop( const char *format, t_printf *pf)
{
	while (*format && pf->ret != -1 && pf->buff.i < pf->buff.size)
	{
		if (*format == '%')
		{
			format++;
			if (ft_getarg(format, &pf->ap, &pf->arg))
			{
				ft_put_char_buff(pf);
				pf->arg.arg = (void *)(long)*format;
				pf->arg.type = CHAR;
				if (pf->ft_write_pf)
					pf->ft_write_pf(pf);
				if (!*format)
					return (1);
			}
			ft_put_arg_buff(pf);
		}
		else
			pf->buff.buff[pf->buff.i++] = *format;
		if (pf->ft_write_pf && pf->buff.i >= pf->buff.size)
			if (pf->ft_write_pf(pf) == -1)
				return (1);
		format++;
	}
	return (0);
}
