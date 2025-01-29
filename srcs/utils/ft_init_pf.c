/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:53:06 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/23 14:09:41 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_pf(t_printf *pf, int fd, char *pf_buff, size_t size)
{
	pf->fd = fd;
	pf->ret = 0;
	pf->buff.buff = pf_buff;
	pf->buff.size = size;
	pf->buff.i = 0;
	pf->arg.arg = NULL;
	pf->ft_write_pf = NULL;
}
