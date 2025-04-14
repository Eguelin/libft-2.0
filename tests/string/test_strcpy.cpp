/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 10:38:33 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrcpyArgs {
	char		*dst;
	const char	*src;
};

static void	test_strcpy_std(const std::vector<std::string> &test_strings);
static void	test_strcpy_null();
static void	test_strcpy_big();

void	test_strcpy(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strcpy" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strcpy_std(test_strings);
	test_strcpy_null();
	if (bigstr)
		test_strcpy_big();
}

static void	test_strcpy_runner(StrcpyArgs &args) {
	args.dst = ft_strcpy(args.dst, args.src);
}

static bool assert_strcpy_result(StrcpyArgs &args) {
	return (args.dst != nullptr && args.src != nullptr && args.dst != args.src && strcmp(args.dst, args.src) == 0);
}

static void	test_strcpy_std(const std::vector<std::string> &test_strings) {
	char	dst[100];

	memset(dst, 10, 100);
	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrcpyArgs args{dst, test_strings[i].c_str()};
		run_test("ft_strcpy(dst, \"" + test_strings[i] + "\")",
			[&]() { test_strcpy_runner(args); },
			[&]() { return assert_strcpy_result(args); },
			NO_SEGV);
	}
}

static void	test_strcpy_null() {
	char	str[1];

	run_test("ft_strcpy(NULL, \"str\")",
		[&]() { ft_strcpy(nullptr, "str"); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcpy(str, NULL)",
		[&]() { ft_strcpy(str, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcpy(NULL, NULL)",
		[&]() { ft_strcpy(nullptr, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strcpy_big() {
	char *dst = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst) {
		std::cerr << "Failed to allocate memory for dst" << std::endl;
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		free(dst);
		return;
	}

	memset(src, 'a', BIG_SIZE - 1);
	StrcpyArgs args{dst, src};
	run_test("ft_strcpy(dst, src)",
		[&]() { test_strcpy_runner(args); },
		[&]() { return assert_strcpy_result(args); },
		NO_SEGV);

	free(dst);
	free(src);
}
