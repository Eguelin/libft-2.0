/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strndup.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 11:43:00 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrndupArgs {
	char		*result;
	const char	*src;
	size_t		n;
};

static void	test_strndup_std(const std::vector<std::string> &test_strings);
static void	test_strndup_null();
static void	test_strndup_big();

void	test_strndup(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strndup" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strndup_std(test_strings);
	test_strndup_null();
	if (bigstr)
		test_strndup_big();
}

static void	test_strndup_runner(StrndupArgs &args) {
	args.result = ft_strndup(args.src, args.n);
	if (args.result == nullptr) {
		std::cerr << "Failed to allocate memory for result" << std::endl;
		return;
	}
}

static bool assert_strndup_result(StrndupArgs &args) {
	return (args.result != nullptr && args.src != nullptr && args.result != args.src && strncmp(args.result, args.src, args.n) == 0);
}

static void	test_strndup_std(const std::vector<std::string> &test_strings) {
	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrndupArgs args{nullptr, test_strings[i].c_str(), test_strings[i].size()};
		run_test("ft_strndup(\"" + test_strings[i] + "\", " + std::to_string(args.n) + ")",
			[&]() { test_strndup_runner(args); },
			[&]() { return assert_strndup_result(args); },
			NO_SEGV);
		free(args.result);
	}

	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrndupArgs args{nullptr, test_strings[i].c_str(), test_strings[i].size() / 2};
		run_test("ft_strndup(\"" + test_strings[i] + "\", " + std::to_string(args.n) + ")",
			[&]() { test_strndup_runner(args); },
			[&]() { return assert_strndup_result(args); },
			NO_SEGV);
		free(args.result);
	}
}

static void	test_strndup_null() {
	run_test("ft_strndup(NULL, 0)",
		[]() { ft_strndup(nullptr, 0); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strndup_big() {
	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		return;
	}

	memset(src, 'a', BIG_SIZE - 1);
	StrndupArgs args{nullptr, src, BIG_SIZE - 1};
	run_test("ft_strndup(str[BIG_SIZE], BIG_SIZE - 1)",
		[&]() { test_strndup_runner(args); },
		[&]() { return assert_strndup_result(args); },
		NO_SEGV);

	free(args.result);
	free(src);
}
