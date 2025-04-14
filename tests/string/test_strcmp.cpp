/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 10:38:22 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrcmpArgs {
	const char	*s1;
	const char	*s2;
	int			result;
};

static void	test_strcmp_std(const std::vector<std::string> &test_strings);
static void	test_strcmp_null();
static void	test_strcmp_big();

void	test_strcmp(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strcmp" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strcmp_std(test_strings);
	test_strcmp_null();
	if (bigstr)
		test_strcmp_big();
}

static void	test_strcmp_runner(StrcmpArgs &args) {
	args.result = ft_strcmp(args.s1, args.s2);
}

static bool assert_strcmp_result(StrcmpArgs &args) {
	return (args.result == 0 && !strcmp(args.s1, args.s2)) ||
		(args.result < 0 && strcmp(args.s1, args.s2) < 0) ||
		(args.result > 0 && strcmp(args.s1, args.s2) > 0);
}

static void	test_strcmp_std(const std::vector<std::string> &test_strings) {

	for (size_t i = 0; i < test_strings.size(); ++i) {

		for (size_t j = 0; j < test_strings.size(); ++j) {
			StrcmpArgs args{test_strings[i].c_str(), test_strings[j].c_str(), 0};

			run_test("ft_strcmp(\"" + test_strings[i] + "\", \"" + test_strings[j] + "\")",
				[&]() { test_strcmp_runner(args); },
				[&]() { return assert_strcmp_result(args); },
				NO_SEGV);
		}
	}
}

static void	test_strcmp_null() {
	run_test("ft_strcmp(NULL, \"str\")",
		[&]() { ft_strcmp(nullptr, "str"); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcmp(\"str\", NULL)",
		[&]() { ft_strcmp("str", nullptr); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcmp(NULL, NULL)",
		[&]() { ft_strcmp(nullptr, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strcmp_big() {
	char *s1 = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!s1) {
		std::cerr << "Failed to allocate memory for s1" << std::endl;
		return;
	}

	char *s2 = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!s2) {
		std::cerr << "Failed to allocate memory for s2" << std::endl;
		free(s1);
		return;
	}
	memset(s1, 'a', BIG_SIZE - 1);
	memset(s2, 'a', BIG_SIZE - 2);
	s2[BIG_SIZE - 2] = 'b';

	StrcmpArgs args{s1, s2, 0};
	run_test("ft_strcmp(s1[BIG_SIZE], s2[BIG_SIZE])",
		[&]() { test_strcmp_runner(args); },
		[&]() { return assert_strcmp_result(args); },
		NO_SEGV);

	args.s2 = s1;
	run_test("ft_strcmp(s1[BIG_SIZE], s1[BIG_SIZE])",
		[&]() { test_strcmp_runner(args); },
		[&]() { return assert_strcmp_result(args); },
		NO_SEGV);

	free(s1);
	free(s2);
}
