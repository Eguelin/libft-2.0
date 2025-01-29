/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:25:28 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_put_arg_buff(t_printf *pf)
{
	void	(*putarg[8])(t_printf *pf);

	putarg[CHAR] = ft_put_char_buff;
	putarg[INT] = ft_put_long_buff;
	putarg[UINT] = ft_put_ulong_buff;
	putarg[HEX] = ft_put_hex_buff;
	putarg[HEX_UP] = ft_put_hexup_buff;
	putarg[STRING] = ft_put_str_buff;
	putarg[PTR] = ft_put_ptr_buff;
	putarg[PERCENT] = ft_put_char_buff;
	putarg[pf->arg.type](pf);
	return ;
}
