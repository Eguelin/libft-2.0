/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_long_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:14:58 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 18:40:34 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_long_buff(t_printf *pf)
{
	t_buff	*buff;
	t_arg	*arg;

	buff = &pf->buff;
	arg = &pf->arg;
	if ((long)arg->value < 0)
	{
		buff->str[buff->i] = '-';
		arg->value = (void *)(-(long)(arg->value));
		buff->i++;
	}
	if (pf->flush && buff->i >= PF_BUFF_SIZE)
		pf->flush(pf);
	ft_put_ulong_buff(pf);
	return ;
}
