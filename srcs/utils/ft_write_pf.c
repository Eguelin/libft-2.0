/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:18:04 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_write_pf(t_printf *pf)
{
	if (write(pf->fd, pf->buff.buff, pf->buff.i) == -1)
	{
		pf->ret = -1;
		return (-1);
	}
	pf->ret += pf->buff.i;
	pf->buff.i = 0;
	return (0);
}
