/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:52:55 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 18:43:09 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_print_loop(t_format *ft, t_printf *pf, va_list *ap)
{
	while (ft->str[ft->i] && pf->ret != -1 && pf->buff.i < PF_BUFF_SIZE)
	{
		if (ft->str[ft->i] == '%')
		{
			if (ft_gettype(ft, &pf->arg))
				return (1);
			ft_getarg(ap, &pf->arg);
			ft_put_arg_buff(pf);
		}
		else
			pf->buff.str[pf->buff.i++] = ft->str[ft->i];
		if (pf->flush && pf->buff.i >= PF_BUFF_SIZE)
			if (pf->flush(pf) == -1)
				return (1);
		ft->i++;
	}
	return (0);
}
