/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:02 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/12 16:26:16 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"

int	ft_flush_buff(t_printf *pf)
{
	size_t	len;

	if (pf->t_str->size - pf->t_str->i > pf->buff.i)
		len = pf->buff.i + 1;
	else
		len = pf->t_str->size - pf->t_str->i;
	ft_strlcpy(pf->t_str->str + pf->t_str->i, pf->buff.str, len);
	pf->t_str->i += len;
	if (pf->ret != -1)
		pf->ret += pf->buff.i;
	return (0);
}
