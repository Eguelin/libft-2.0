/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 19:04:43 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrncmpArgs {
	const char	*s1;
	const char	*s2;
	size_t		n;
	int			result;
};

static void	test_strncmp_std(const std::vector<std::string>& test_strings);
static void	test_strncmp_null();
static void	test_strncmp_big();

void	test_strncmp(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strncmp" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strncmp_std(test_strings);
	test_strncmp_null();
	test_strncmp_big();
}

static void	test_strncmp_runner(StrncmpArgs& args) {
	args.result = ft_strncmp(args.s1, args.s2, args.n);
}

static bool assert_strncmp_result(StrncmpArgs& args) {
	return (args.result == 0 && !strncmp(args.s1, args.s2, args.n)) ||
		(args.result < 0 && strncmp(args.s1, args.s2, args.n) < 0) ||
		(args.result > 0 && strncmp(args.s1, args.s2, args.n) > 0);
}

static void	test_strncmp_std(const std::vector<std::string>& test_strings) {

	for (size_t i = 0; i < test_strings.size(); ++i) {

		for (size_t j = 0; j < test_strings.size(); ++j) {
			StrncmpArgs args{test_strings[i].c_str(), test_strings[j].c_str(), test_strings[i].size(), 0};

			run_test("ft_strncmp(\"" + test_strings[i] + "\", \"" + test_strings[j] + "\" " + std::to_string(args.n) + ")",
				[&]() { test_strncmp_runner(args); },
				[&]() { return assert_strncmp_result(args); },
				NO_SEGV);
		}
	}

	StrncmpArgs args{"Hello, World!", "Helloo, World!", 0, 0};
	for (size_t i = 0; i < test_strings[0].size() + 3; ++i) {
		args.n = i;
		run_test("ft_strncmp(\"Hello, World!\", \"Helloo, World!\", " + std::to_string(args.n) + ")",
			[&]() { test_strncmp_runner(args); },
			[&]() { return assert_strncmp_result(args); },
			NO_SEGV);
	}
}

static void	test_strncmp_null() {
	run_test("ft_strncmp(NULL, \"str\", 2)",
		[]() { ft_strncmp(nullptr, "str", 2); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strncmp(\"str\", NULL, 3)",
		[]() { ft_strncmp("str", nullptr, 3); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strncmp(NULL, NULL, 2)",
		[]() { ft_strncmp(nullptr, nullptr, 2); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strncmp_big() {
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

	StrncmpArgs args{s1, s2, BIG_SIZE - 1, 0};
	run_test("ft_strncmp(s1[BIG_SIZE], s2[BIG_SIZE], BIG_SIZE - 1)",
		[&]() { test_strncmp_runner(args); },
		[&]() { return assert_strncmp_result(args); },
		NO_SEGV);

	args.s2 = s1;
	run_test("ft_strncmp(s1[BIG_SIZE], s1[BIG_SIZE], BIG_SIZE - 1)",
		[&]() { test_strncmp_runner(args); },
		[&]() { return assert_strncmp_result(args); },
		NO_SEGV);

	free(s1);
	free(s2);
}
