/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/01/30 16:18:39 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.h"

sigjmp_buf env;
struct sigaction sa;

void	test_strlen(char **tab);
void	test_strcpy(char **tab);
void	test_strcmp(char **tab);
void	test_write(char **tab);
void	test_read(char **tab);
void	test_strdup(char **tab);

int main()
{
	char *tab[] = {
		"Hello, World!",
		"lorem ipsum dolor sit amet",
		"test",
		"3 + 3 = 9",
		"\211",
		"",
		NULL};

	sigemptyset(&sa.sa_mask);
	test_strlen(tab);
	test_strcpy(tab);
	test_strcmp(tab);
	return (0);
}

void	test_strlen(char **tab)
{
	int		i = 0;
	size_t	len;
	char	*str;

	// Classic tests
	printf(PURPLE"\t--- ft_strlen ---\n"RESET);
	while (tab[i])
	{
		len = 0;
		ASSERT_EXPR_CONDITION(len = ft_strlen(tab[i]), len == strlen(tab[i]));
		printf(BLUE"ft_strlen(\"%s\") = %lu\n"RESET, tab[i], len);
		i++;
	}

	// NULL tests
	len = 0;
	EXPECT_SEGFAULT(ft_strlen(NULL));
	printf(BLUE"ft_strlen(NULL)\n"RESET);

	// Ferry big string test
	len = 0;
	str = calloc(UINT_MAX, sizeof(char));
	if (!str)
	{
		printf(RED"failed to allocate str[UINT_MAX]\n"RESET);
		return;
	}
	str = memset(str, 'c', UINT_MAX - 1);
	ASSERT_EXPR_CONDITION(len = ft_strlen(str), len == strlen(str));
	printf(BLUE"ft_strlen(str[UINT_MAX]) = %lu\n"RESET, len);
	free(str);
}

void test_strcpy(char **tab)
{
	int		i = 0;
	char	*src;
	char	*dest;
	char	destNULL[1];

	// Classic tests
	printf(PURPLE"\t--- ft_strcpy ---\n"RESET);
	while (tab[i])
	{
		dest = calloc(strlen(tab[i]) + 1, sizeof(char));
		if (!dest)
			exit_error("failed to allocate str", NULL);
		ASSERT_EXPR_CONDITION(ft_strcpy(dest, tab[i]), !strcmp(dest, tab[i]) && dest != tab[i]);
		printf(BLUE"ft_strcpy(dest, \"%s\") = \"%s\"\n"RESET, tab[i], dest);
		free(dest);
		i++;
	}

	// NULL tests
	EXPECT_SEGFAULT(ft_strcpy(destNULL, NULL));
	printf(BLUE"ft_strcpy(dest, NULL)\n"RESET);
	EXPECT_SEGFAULT(ft_strcpy(NULL, "test"));
	printf(BLUE"ft_strcpy(NULL, src)\n"RESET);

	// Ferry big string test
	src = calloc(UINT_MAX, sizeof(char));
	if (!src)
		exit_error("failed to allocate src", NULL);
	src = memset(src, 'c', UINT_MAX - 1);
	dest = calloc(UINT_MAX, sizeof(char));
	if (!dest)
		exit_error("failed to allocate dest", src);
	ASSERT_EXPR_CONDITION(ft_strcpy(dest, src), !strcmp(dest, src) && dest != src);
	printf(BLUE"ft_strcpy(dest, str[UINT_MAX])\n"RESET);
	free(src);
	free(dest);
}

void test_strcmp(char **tab)
{
	int		i = 0;
	int		j;
	int		ret;
	char	*str;

	// Classic tests
	printf(PURPLE"\t--- ft_strcmp ---\n"RESET);
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			ret = 0;
			ASSERT_EXPR_CONDITION(ret = ft_strcmp(tab[i], tab[j]),
			ret > 0 ? strcmp(tab[i], tab[j]) > 0 : \
			ret < 0 ? strcmp(tab[i], tab[j]) < 0 : \
			ret == strcmp(tab[i], tab[j]));
			printf(BLUE"ft_strcmp(\"%s\", \"%s\") = %d\n"RESET, tab[i], tab[j], ret);
			j++;
		}
		i++;
	}

	// NULL tests
	ret = 0;
	EXPECT_SEGFAULT(ft_strcmp("test", NULL));
	printf(BLUE"ft_strcmp(dest, NULL)\n"RESET);
	ret = 0;
	EXPECT_SEGFAULT(ft_strcmp(NULL, "test"));
	printf(BLUE"ft_strcmp(NULL, src)\n"RESET);
	ret = 0;
	EXPECT_SEGFAULT(ft_strcmp(NULL, 0x0));
	printf(BLUE"ft_strcmp(NULL, 0x0)\n"RESET);

	// Ferry big string test
	ret = 0;
	str = calloc(UINT_MAX, sizeof(char));
	if (!str)
		exit_error("failed to allocate str", NULL);
	str = memset(str, 'c', UINT_MAX - 1);
	ASSERT_EXPR_CONDITION(ret = ft_strcmp(str, str), ret == 0);
	printf(BLUE"ft_strcmp(str[UINT_MAX], str[UINT_MAX]) = %d\n"RESET, ret);
	ret = 0;
	ASSERT_EXPR_CONDITION(ret = ft_strcmp(str, str + 1), ret > 0);
	printf(BLUE"ft_strcmp(str[UINT_MAX], str[UINT_MAX - 1]) = %d\n"RESET, ret);
	ret = 0;
	ASSERT_EXPR_CONDITION(ret = ft_strcmp(str + 1, str), ret < 0);
	printf(BLUE"ft_strcmp(str[UINT_MAX - 1], str[UINT_MAX]) = %d\n"RESET, ret);
	free(str);
}
