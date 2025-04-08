/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 11:13:59 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrdupArgs {
	char		*result;
	const char	*src;
};

static void	test_strdup_std(const std::vector<std::string>& test_strings);
static void	test_strdup_null();
static void	test_strdup_big();

void	test_strdup(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strdup" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strdup_std(test_strings);
	test_strdup_null();
	test_strdup_big();
}

static void	test_strdup_runner(StrdupArgs& args) {
	args.result = ft_strdup(args.src);
	if (args.result == nullptr) {
		std::cerr << "Failed to allocate memory for result" << std::endl;
		return;
	}
}

static bool assert_strdup_result(StrdupArgs& args) {
	return (args.result != nullptr && args.src != nullptr && strcmp(args.result, args.src) == 0);
}

static void	test_strdup_std(const std::vector<std::string>& test_strings) {
	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrdupArgs args{nullptr, test_strings[i].c_str()};
		run_test("ft_strdup(\"" + test_strings[i] + "\")",
			[&]() { test_strdup_runner(args); },
			[&]() { return assert_strdup_result(args); },
			NO_SEGV);
		free(args.result);
	}
}

static void	test_strdup_null() {
	run_test("ft_strdup(NULL)",
		[&]() { ft_strdup(nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strdup_big() {
	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		return;
	}

	memset(src, 'a', BIG_SIZE - 1);
	StrdupArgs args{nullptr, src};
	run_test("ft_strdup(str[BIG_SIZE])",
		[&]() { test_strdup_runner(args); },
		[&]() { return assert_strdup_result(args); },
		NO_SEGV);

	free(args.result);
	free(src);
}
