/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:27:27 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/12 16:32:52 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

void	ft_init_t_printf(t_printf *pf, int fd, int (*flush)(t_printf *),
		t_string *t_str)
{
	ft_bzero(pf, sizeof(t_printf));
	pf->fd = fd;
	pf->flush = flush;
	pf->t_str = t_str;
}
