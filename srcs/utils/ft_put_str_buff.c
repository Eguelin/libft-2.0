/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:02 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
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
	str = (char *)arg->arg;
	if (str == NULL)
		str = "(null)";
	while (*str != 0 && buff->i < buff->size)
	{
		buff->buff[buff->i] = *str;
		buff->i++;
		str++;
		if (pf->ft_write_pf && buff->i >= buff->size)
			if (pf->ft_write_pf(pf) == -1)
				return ;
	}
	return ;
}
