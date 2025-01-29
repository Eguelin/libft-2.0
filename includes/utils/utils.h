/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:08:28 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/29 18:23:01 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <unistd.h>

# define PRINTF_BUFF_SIZE 1024

typedef enum e_arg_type
{
	CHAR,
	INT,
	UINT,
	HEX,
	HEX_UP,
	STRING,
	PTR,
	PERCENT
}	t_arg_type;

typedef struct s_arg
{
	void		*arg;
	t_arg_type	type;
}	t_arg;

typedef struct s_buff
{
	char	*buff;
	size_t	size;
	size_t	i;
}	t_buff;

typedef struct s_printf
{
	int			fd;
	int			ret;
	const char	*format;
	va_list		ap;
	t_arg		arg;
	t_buff		buff;
	int			(*ft_write_pf)(struct s_printf *);
}	t_printf;

int		ft_print_loop( const char *format, t_printf *pf);
void	ft_put_arg_buff(t_printf *pf);
void	ft_put_char_buff(t_printf *pf);
void	ft_put_hex_buff(t_printf *pf);
void	ft_put_hexup_buff(t_printf *pf);
void	ft_put_long_buff(t_printf *pf);
void	ft_put_ptr_buff(t_printf *pf);
void	ft_put_str_buff(t_printf *pf);
void	ft_put_ulong_buff(t_printf *pf);
void	ft_put_ulongb_buff(t_printf *pf, const char *base);
void	ft_putargbuff(t_printf *pf);
int		ft_getarg(const char *format, va_list *ap, t_arg *arg);
void	ft_init_pf(t_printf *pf, int fd, char *pf_buff, size_t size);
int		ft_write_pf(t_printf *pf);

#endif
