/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:44:13 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 16:59:33 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifdef __cplusplus
extern "C" {
# endif

/* ************************************************************************** */
/*                              string functions                              */
/* ************************************************************************** */

/*	Concatenates the string pointed to by src to the end of the string pointed
	to by dst.

	The strings may not overlap, and the dstination string dst must be large
	enough to receive the copy.

	Returns a pointer to the dstination string dst. */
char	*ft_strcat(char *dst, const char *src);
/*	Locates the first occurrence of c (converted to a char) in the string
	pointed to by s.

	Returns a pointer to the located character, or NULL if the character does
	not appear in the string. */
char	*ft_strchr(const char *s, int c);
/*	Compares the two strings s1 and s2.

	Returns an integer less than, equal to, or greater than zero if s1 is found,
	respectively, to be less than, to match, or be greater than s2. */
int		ft_strcmp(const char *s1, const char *s2);
/*	Copies the string pointed to by src, including the terminating null byte
	('\0'), to the buffer pointed to by dst.

	The strings may not overlap, and the dstination string dst must be large
	enough to receive the copy.

	Returns a pointer to the dstination string dst. */
char	*ft_strcpy(char *dst, const char *src);
/*	Allocates sufficient memory for a copy of the string s, does the copy,
	and returns a pointer to it.

	The pointer may subsequently be used as an argument to the function free(3). */
char	*ft_strdup(const char *s);
/*	Concatenates the string pointed to by src to the end of the string pointed
	to by dst, up to size - 1 characters.

	The strings may not overlap, and the dstination string dst must be large
	enough to receive the copy.

	Returns the total length of the string it tried to create. */
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/*	Copies up to size - 1 characters from the string pointed to by src to the
	string pointed to by dst, NUL-terminating the result if size is not 0.

	The strings may not overlap, and the dstination string dst must be large
	enough to receive the copy.

	Returns the length of the string it tried to create. */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/*	Returns length of the string s. */
size_t	ft_strlen(const char *s);
# ifdef __cplusplus
}
# endif

#endif
