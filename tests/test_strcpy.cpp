/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 11:44:23 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrcpyArgs {
	char		*dest;
	const char	*src;
};

static void	test_strcpy_std(const std::vector<std::string>& test_strings);
static void	test_strcpy_null();
static void	test_strcpy_big();

void	test_strcpy(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strcpy" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strcpy_std(test_strings);
	test_strcpy_null();
	test_strcpy_big();
}

static void	test_strcpy_runner(StrcpyArgs& args) {
	args.dest = ft_strcpy(args.dest, args.src);
}

static bool assert_strcpy_result(StrcpyArgs& args) {
	return (args.dest != nullptr && args.src != nullptr && args.dest != args.src && strcmp(args.dest, args.src) == 0);
}

static void	test_strcpy_std(const std::vector<std::string>& test_strings) {
	char	*dest = static_cast<char *>(malloc(100));
	if (!dest) {
		std::cerr << "Failed to allocate memory for dest" << std::endl;
		return;
	}

	memset(dest, 10, 100);
	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrcpyArgs args{dest, test_strings[i].c_str()};
		run_test("ft_strcpy(dest, \"" + test_strings[i] + "\")",
			[&]() { test_strcpy_runner(args); },
			[&]() { return assert_strcpy_result(args); },
			NO_SEGV);
	}

	free(dest);
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
	char *dest = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dest) {
		std::cerr << "Failed to allocate memory for dest" << std::endl;
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		free(dest);
		return;
	}

	memset(src, 'a', BIG_SIZE - 1);
	StrcpyArgs args{dest, src};
	run_test("ft_strcpy(dest, src)",
		[&]() { test_strcpy_runner(args); },
		[&]() { return assert_strcpy_result(args); },
		NO_SEGV);

	free(dest);
	free(src);
}
