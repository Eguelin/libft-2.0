/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_long_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:14:58 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_long_buff(t_printf *pf)
{
	t_buff	*buff;
	t_arg	*arg;

	buff = &pf->buff;
	arg = &pf->arg;
	if ((long)arg->arg < 0)
	{
		buff->buff[buff->i] = '-';
		arg->arg = (void *)(-(long)(arg->arg));
		buff->i++;
	}
	if (pf->ft_write_pf && buff->i >= buff->size)
		pf->ft_write_pf(pf);
	ft_put_ulong_buff(pf);
	return ;
}
