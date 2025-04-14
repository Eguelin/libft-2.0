/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 10:38:14 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrrchrArgs {
	char		c;
	char		*result;
	const char	*src;
};

static void	test_strrchr_std(const std::vector<std::string> &test_strings);
static void	test_strrchr_null();
static void	test_strrchr_big();

void	test_strrchr(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strrchr" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strrchr_std(test_strings);
	test_strrchr_null();
	if (bigstr)
		test_strrchr_big();
}

static void	test_strrchr_runner(StrrchrArgs &args) {
	args.result = ft_strrchr(args.src, args.c);
}

static bool assert_strrchr_result(StrrchrArgs &args) {
	return args.result == strrchr(args.src, args.c);
}

static void	test_strrchr_std(const std::vector<std::string> &test_strings) {
	std::string	charset = "abcGHI012\212";

	for (size_t i = 0; i < test_strings.size(); ++i) {

		for (std::string::size_type j = 0; j < test_strings[i].size(); ++j) {
			char c = test_strings[i][j];
			StrrchrArgs args{c, NULL, test_strings[i].c_str()};

			run_test("ft_strrchr(\"" + test_strings[i] + "\", '" + c + "')",
				[&]() { test_strrchr_runner(args); },
				[&]() { return assert_strrchr_result(args); },
				NO_SEGV);
		}

		for (std::string::size_type j = 0; j < charset.size(); ++j) {
			char c = charset[j];
			StrrchrArgs args{c, NULL, test_strings[i].c_str()};

			run_test("ft_strrchr(\"" + test_strings[i] + "\", '" + c + "')",
				[&]() { test_strrchr_runner(args); },
				[&]() { return assert_strrchr_result(args); },
				NO_SEGV);
		}
	}
}

static void	test_strrchr_null() {
	run_test("ft_strrchr(NULL, c)",
		[&]() { ft_strrchr(nullptr, 'c'); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strrchr_big() {
	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		return;
	}

	memset(src, 'c', BIG_SIZE - 1);
	src[BIG_SIZE - 2] = 'd';
	StrrchrArgs args{'c', NULL, src};
	run_test("ft_strrchr(dst[BIG_SIZE], 'd')",
		[&]() { test_strrchr_runner(args); },
		[&]() { return assert_strrchr_result(args); },
		NO_SEGV);

	free(src);
}
