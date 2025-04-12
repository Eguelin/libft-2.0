/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_t_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:27:27 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/11 19:25:49 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_init_t_string(t_string *t_str, char *str, size_t size)
{
	t_str->str = str;
	t_str->size = size;
	t_str->i = 0;
}
