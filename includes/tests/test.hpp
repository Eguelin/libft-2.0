/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:28:33 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 16:59:44 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include <iostream>
#include <climits>
#include <cstring>
#include <functional>
#include <csignal>
#include <vector>
#include <setjmp.h>
#include "libft.h"

#define BIG_SIZE static_cast<size_t>(INT_MAX) + 100

enum	SegvExpectation {
	NO_SEGV,
	EXPECT_SEGV
};

extern sigjmp_buf	env;

void	catch_segfault();
void	default_sigaction();
void	run_test(const std::string& label, std::function<void()> test_func, std::function<bool()> assert_func, SegvExpectation expect_segv);

void	test_strcat(std::vector<std::string> test_strings);
void	test_strchr(std::vector<std::string> test_strings);
void	test_strcmp(std::vector<std::string> test_strings);
void	test_strcpy(std::vector<std::string> test_strings);
void	test_strdup(std::vector<std::string> test_strings);
void	test_strlcat(std::vector<std::string> test_strings);
void	test_strlcpy(std::vector<std::string> test_strings);

#endif
