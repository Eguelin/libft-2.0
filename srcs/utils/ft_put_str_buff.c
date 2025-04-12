/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:02 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 18:40:43 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_str_buff(t_printf *pf)
{
	char	*str;
	t_buff	*buff;
	t_arg	*arg;

	buff = &pf->buff;
	arg = &pf->arg;
	str = (char *)arg->value;
	if (str == NULL)
		str = "(null)";
	while (*str != 0 && buff->i < PF_BUFF_SIZE)
	{
		buff->str[buff->i] = *str;
		buff->i++;
		str++;
		if (pf->flush && buff->i >= PF_BUFF_SIZE)
			if (pf->flush(pf) == -1)
				return ;
	}
	return ;
}
