/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstr.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 12:11:40 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrstrArgs {
	const char	*big;
	const char	*little;
	char		*result;
};

static void	test_strstr_std(const std::vector<std::string> &test_strings);
static void	test_strstr_null();
static void	test_strstr_big();

void	test_strstr(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strstr" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strstr_std(test_strings);
	test_strstr_null();
	if (bigstr)
		test_strstr_big();
}

static void	test_strstr_runner(StrstrArgs &args) {
	args.result = ft_strstr(args.big, args.little);
}

static bool assert_strstr_result(StrstrArgs &args) {
	return (args.result == strstr(args.big, args.little));
}

static void	test_strstr_std(const std::vector<std::string> &test_strings) {
	std::vector<std::string> test_substrings = gen_substrings(test_strings);

	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrstrArgs args{test_strings[i].c_str(), test_substrings[i].c_str(), nullptr};
		run_test("ft_strstr(\"" + test_strings[i] + "\", \"" + test_substrings[i] + "\")",
			[&]() { test_strstr_runner(args); },
			[&]() { return assert_strstr_result(args); },
			NO_SEGV);
	}

	for (size_t i = 0; i < test_strings[0].size(); ++i) {
		StrstrArgs args{test_strings[0].c_str(), test_strings[0].c_str() + i, nullptr};
		run_test("ft_strstr(\"" + std::string(args.big) + "\", \"" + args.little + "\")",
			[&]() { test_strstr_runner(args); },
			[&]() { return assert_strstr_result(args); },
			NO_SEGV);
	}

	StrstrArgs args{test_strings[0].c_str(), "\212", nullptr};
	run_test("ft_strstr(\"" + std::string(args.big) + "\", \"" + args.little + "\")",
	[&]() { test_strstr_runner(args); },
	[&]() { return assert_strstr_result(args); },
	NO_SEGV);
}

static void	test_strstr_null() {
	run_test("ft_strstr(NULL, \"str\")",
		[]() { ft_strstr(nullptr, "str"); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strstr(\"str\", NULL)",
		[]() { ft_strstr("str", nullptr); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strstr(NULL, NULL)",
		[]() { ft_strstr(nullptr, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strstr_big() {
	char *big = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!big) {
		std::cerr << "Failed to allocate memory for big" << std::endl;
		return;
	}

	memset(big, 'a', BIG_SIZE - 1);
	big[BIG_SIZE - 4] = 'b';
	StrstrArgs args{big, "b", nullptr};
	run_test("ft_strstr(big[BIG_SIZE], "", BIG_SIZE - 1)",
		[&]() { test_strstr_runner(args); },
		[&]() { return assert_strstr_result(args); },
		NO_SEGV);

	free(big);
}
