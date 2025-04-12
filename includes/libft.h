/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:44:13 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/12 17:02:23 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/* ************************************************************************** */
/*                              print functions                               */
/* ************************************************************************** */

/*	Writes the string s to the file descriptor fd.

	Returns the number of characters written. (Excluding the null byte used to
	terminate output to strings). */
int		ft_dprintf(int fd, const char *format, ...);
/*	Write formatted output to stdout.

	Returns the number of characters printed (excluding the null byte used to
	terminate output to strings). */
int		ft_printf(const char *format, ...);
/*	Write formatted output to the string str.

	Returns the number of characters printed (excluding the null byte used to
	terminate output to strings). */
int		ft_snprintf(char *str, size_t size, const char *format, ...);
/*	Write formatted output to the string str.

	Returns the number of characters printed (excluding the null byte used to
	terminate output to strings). */
int		ft_sprintf(char *str, const char *format, ...);

/* ************************************************************************** */
/*                              string functions                              */
/* ************************************************************************** */

/*	Initializes the first n bytes of the block of memory pointed by s to
	zero. */
void	ft_bzero(void *s, size_t n);
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
/*	Duplicates the string s.

	Returns a pointer to the duplicated string, or NULL if the allocation fails.
	The returned string must be freed with free(3). */
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
/*	Compares not more than n characters of the strings s1 and s2.

	Returns an integer less than, equal to, or greater than zero if s1 is found,
	respectively, to be less than, to match, or be greater than s2. */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*	Duplicates the string s, up to n characters.

	Returns a pointer to the duplicated string, or NULL if the allocation fails.
	The returned string must be freed with free(3). */
char	*ft_strndup(const char *s, size_t n);
/*	Locates the first occurrence of the null-terminated string little in the
	string big, where not more than n characters are searched.

	Returns a pointer to the beginning of the located substring, or NULL if the
	substring is not found. */
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif
