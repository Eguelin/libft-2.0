/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 10:37:53 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrcatArgs {
	char		*dst;
	const char	*src;
	std::string	expected;
};

static void	test_strcat_std(const std::vector<std::string> &test_strings);
static void	test_strcat_null();
static void	test_strcat_big();

void	test_strcat(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_strcat" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strcat_std(test_strings);
	test_strcat_null();
	if (bigstr)
		test_strcat_big();
}

static void	test_strcat_runner(StrcatArgs &args) {
	args.dst = ft_strcat(args.dst, args.src);
}

static bool assert_strcat_result(StrcatArgs &args) {
	return args.dst && args.expected == args.dst;
}

static void	test_strcat_std(const std::vector<std::string> &test_strings) {
	char	dst[100];

	memset(dst, 0, sizeof(dst));
	for (size_t i = 0; i < test_strings.size(); ++i) {
		strcpy(dst, test_strings[i].c_str());

		for (size_t j = 0; j < test_strings.size(); ++j) {
			std::string expected = std::string(dst) + test_strings[j];
			StrcatArgs args{dst, test_strings[j].c_str(), expected};

			run_test("ft_strcat(\"" + test_strings[i] + "\", \"" + test_strings[j] + "\")",
				[&]() { test_strcat_runner(args); },
				[&]() { return assert_strcat_result(args); },
				NO_SEGV);
		}
	}
}

static void	test_strcat_null() {
	char dst[1] = {0};

	run_test("ft_strcat(dst, NULL)",
		[&]() { ft_strcat(dst, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcat(NULL, src)",
		[&]() { ft_strcat(nullptr, "test"); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strcat(NULL, NULL)",
		[&]() { ft_strcat(nullptr, nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strcat_big() {
	char *dst = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst) {
		std::cerr << "Failed to allocate memory for dst" << std::endl;
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE - 50, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		free(dst);
		return;
	}

	memset(dst, 'c', 50);
	memset(src, 'c', BIG_SIZE - 51);
	StrcatArgs args{dst, src, std::string(dst) + src};
	run_test("ft_strcat(dst[BIG_SIZE], src[BIG_SIZE - 50])",
		[&]() { test_strcat_runner(args); },
		[&]() { return assert_strcat_result(args); },
		NO_SEGV);

	args.dst[BIG_SIZE - 50] = '\0';
	src[49] = '\0';
	args.src = src;
	run_test("ft_strcat(dst[BIG_SIZE], src[50])",
		[&]() { test_strcat_runner(args); },
		[&]() { return assert_strcat_result(args); },
		NO_SEGV);

	free(src);
	free(dst);
}
