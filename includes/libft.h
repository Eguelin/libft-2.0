/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:44:13 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/29 19:38:18 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

/* ************************************************************************** */
/*                              string functions                              */
/* ************************************************************************** */

/*	Returns length of the string s. */
size_t	ft_strlen(const char *s);
/*	Locates the first occurrence of c (converted to a char) in the string
	pointed to by s.

	Returns a pointer to the located character, or NULL if the character does
	not appear in the string. */
char	*ft_strchr(const char *s, int c);
/*	Copies the string pointed to by src, including the terminating null byte
	('\0'), to the buffer pointed to by dest.

	The strings may not overlap, and the destination string dest must be large
	enough to receive the copy.

	Returns a pointer to the destination string dest. */
char	*strcpy(char *dest, const char *src);
/*	Copies at most n bytes of the string pointed to by src, including the
	terminating null byte ('\0'), to the buffer pointed to by dest.

	The strings may not overlap, and the destination string dest must be large
	enough to receive the copy.

	Returns a pointer to the destination string dest. */
char	*ft_strncpy(char *dest, const char *src, size_t n);
/*	Copies up to size - 1 characters from the NUL-terminated string src to
	dst, NUL-terminating the result.

	Returns the total length of the string it tried to create. */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*	Compares the two strings s1 and s2.

	Returns an integer less than, equal to, or greater than zero if s1 is found,
	respectively, to be less than, to match, or be greater than s2. */
int		strcmp(const char *s1, const char *s2);
/*	Compares at most the first n bytes of s1 and s2.

	Returns an integer less than, equal to, or greater than zero if s1 is found,
	respectively, to be less than, to match, or be greater than s2. */
int		strncmp(const char *s1, const char *s2, size_t n);

/* ************************************************************************** */
/*                              print functions                               */
/* ************************************************************************** */

/*	Prints the string in the standard output with the format specified in
	the format string.

	returns the number of characters printed or -1 if an error occurred. */
int		ft_printf(const char *format, ...);
/*	Prints the string in the standard output with the format specified in
	the format string.

	returns the number of characters printed or -1 if an error occurred. */
int		ft_dprintf(int fd, const char *format, ...);
/*	Prints the string in the standard output with the format specified in
	the format string.

	returns the number of characters printed or -1 if an error occurred. */
int		ft_sprintf(char *str, const char *format, ...);
/*	Prints the string in the standard output with the format specified in
	the format string.

	returns the number of characters printed or -1 if an error occurred. */
int		ft_snprintf(char *str, size_t size, const char *format, ...);

#endif
