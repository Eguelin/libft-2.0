/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/07 12:32:04 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrchrArgs {
	char c;
	char *result;
	const char *src;
};

static void	test_strchr_std(const std::vector<std::string>& test_strings);
static void	test_strchr_null();
static void	test_strchr_big();

void	test_strchr(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strchr" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strchr_std(test_strings);
	test_strchr_null();
	test_strchr_big();
}

static void	test_strchr_runner(StrchrArgs& args) {
	args.result = ft_strchr(args.src, args.c);
}

static bool assert_strchr_result(StrchrArgs& args) {
	return args.result == strchr(args.src, args.c);
}

static void	test_strchr_std(const std::vector<std::string>& test_strings) {
	std::string	charset = "abcGHI012\212";

	for (size_t i = 0; i < test_strings.size(); ++i) {

		for (std::string::size_type j = 0; j < test_strings[i].size(); ++j) {
			char c = test_strings[i][j];
			StrchrArgs args{c, NULL, test_strings[i].c_str()};

			run_test("ft_strchr(\"" + test_strings[i] + "\", '" + c + "')",
				[&]() { test_strchr_runner(args); },
				[&]() { return assert_strchr_result(args); },
				NO_SEGV);
		}

		for (std::string::size_type j = 0; j < charset.size(); ++j) {
			char c = charset[j];
			StrchrArgs args{c, NULL, test_strings[i].c_str()};

			run_test("ft_strchr(\"" + test_strings[i] + "\", '" + c + "')",
				[&]() { test_strchr_runner(args); },
				[&]() { return assert_strchr_result(args); },
				NO_SEGV);
		}
	}
}

static void	test_strchr_null() {
	run_test("ft_strchr(NULL, c)",
		[&]() { ft_strchr(nullptr, 'c'); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strchr_big() {
	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		return;
	}

	memset(src, 'c', BIG_SIZE - 1);
	src[BIG_SIZE - 2] = 'd';
	StrchrArgs args{'c', NULL, src};
	run_test("ft_strchr(dest[BIG_SIZE], 'd')",
		[&]() { test_strchr_runner(args); },
		[&]() { return assert_strchr_result(args); },
		NO_SEGV);

	free(src);
}
