/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/09 16:43:25 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrnstrArgs {
	const char	*big;
	const char	*little;
	size_t		len;
	char		*result;
};

static void	test_strnstr_std();
static void	test_strnstr_null();
static void	test_strnstr_big();

void	test_strnstr() {
	std::cout << "\033[1;34m" << "ft_strnstr" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strnstr_std();
	test_strnstr_null();
	test_strnstr_big();
}

static void	test_strnstr_runner(StrnstrArgs& args) {
	args.result = ft_strnstr(args.big, args.little, args.len);
}

static char	*strnstr_ref(const char *big, const char *little, size_t len) {
	size_t	pos = std::string(big, len).find(little);

	if (pos == std::string::npos)
		return nullptr;
	return const_cast<char *>(big + pos);
}

static bool assert_strnstr_result(StrnstrArgs& args) {
	return (args.result == strnstr_ref(args.big, args.little, args.len));
}

static void	test_strnstr_std() {
	std::vector<std::string> test_strings = {
		"Hello, World!",
		"lorem ipsum dolor sit amet",
		"test",
		"3 + 3 = 9",
		"\211\212",
		""
	};

	std::vector<std::string> test_substrings = {
		", Wor",
		"sit",
		"t",
		"3 = 9",
		"\211\212",
		""
	};

	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrnstrArgs args{test_strings[i].c_str(), test_substrings[i].c_str(), test_strings[i].size(), nullptr};
		run_test("ft_strnstr(\"" + test_strings[i] + "\", \"" + test_substrings[i] + "\", " + std::to_string(args.len) + ")",
			[&]() { test_strnstr_runner(args); },
			[&]() { return assert_strnstr_result(args); },
			NO_SEGV);
	}

	StrnstrArgs args{test_strings[0].c_str(), test_substrings[0].c_str(), 0, nullptr};
	for (size_t i = 0; i < test_strings[0].size() + 3; ++i) {
		args.len = i;
		run_test("ft_strnstr(\"" + test_strings[0] + "\", \"" + test_substrings[0] + "\", " + std::to_string(args.len) + ")",
			[&]() { test_strnstr_runner(args); },
			[&]() { return assert_strnstr_result(args); },
			NO_SEGV);
	}
}

static void	test_strnstr_null() {
	run_test("ft_strnstr(NULL, \"str\", 2)",
		[]() { ft_strnstr(nullptr, "str", 3); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strnstr(\"str\", NULL, 3)",
		[]() { ft_strnstr("str", nullptr, 3); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strnstr(NULL, NULL, 2)",
		[]() { ft_strnstr(nullptr, nullptr, 3); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strnstr_big() {
	char *big = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!big) {
		std::cerr << "Failed to allocate memory for big" << std::endl;
		return;
	}

	memset(big, 'a', BIG_SIZE - 1);
	big[BIG_SIZE - 4] = 'b';
	StrnstrArgs args{big, "b", BIG_SIZE - 1, nullptr};
	run_test("ft_strnstr(big[BIG_SIZE], "", BIG_SIZE - 1)",
		[&]() { test_strnstr_runner(args); },
		[&]() { return assert_strnstr_result(args); },
		NO_SEGV);

	free(big);
}
