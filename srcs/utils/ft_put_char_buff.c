/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:25:34 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_char_buff(t_printf *pf)
{
	t_buff	*buff;
	t_arg	*arg;

	buff = &pf->buff;
	arg = &pf->arg;
	if (buff->i >= buff->size)
		return ;
	buff->buff[buff->i] = (char)(long)arg->arg;
	buff->i++;
	if (pf->ft_write_pf && buff->i >= buff->size)
		pf->ft_write_pf(pf);
	return ;
}
