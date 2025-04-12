/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:36:34 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 15:02:05 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_ptr_buff(t_printf *pf)
{
	void	*ptr;

	ptr = pf->arg.value;
	if (!ptr)
	{
		pf->arg.value = "(nil)";
		ft_put_str_buff(pf);
		return ;
	}
	pf->arg.value = "0x";
	ft_put_str_buff(pf);
	pf->arg.value = ptr;
	ft_put_ulongb_buff(pf, "0123456789abcdef");
	return ;
}
