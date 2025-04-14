/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:28:33 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 11:03:54 by eguelin          ###   ########.fr       */
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
#include <map>
#include <setjmp.h>
extern "C" {
	#include "libft.h"
}

#define BIG_SIZE static_cast<size_t>(INT_MAX) + 100

enum	SegvExpectation {
	NO_SEGV,
	EXPECT_SEGV
};

extern sigjmp_buf	env;

void	catch_segfault();
void	default_sigaction();
void	run_test(const std::string& label, std::function<void()> test_func, std::function<bool()> assert_func, SegvExpectation expect_segv);

void	test_str(bool bigstr, const std::vector<std::string> &functests);
void	test_strcat(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strchr(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strcmp(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strcpy(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strdup(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strlcat(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strlcpy(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strlen(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strncmp(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strndup(const std::vector<std::string> &test_strings, bool bigstr);
void	test_strnstr(const std::vector<std::string> &test_strings, bool bigstr);

#endif
