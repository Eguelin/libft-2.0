/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 12:03:40 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrcatArgs {
	char		*dest;
	const char	*src;
	std::string	expected;
};

static void	test_strcat_std(const std::vector<std::string>& test_strings);
static void	test_strcat_null();
static void	test_strcat_big();

void	test_strcat(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strcat" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strcat_std(test_strings);
	test_strcat_null();
	test_strcat_big();
}

static void	test_strcat_runner(StrcatArgs& args) {
	args.dest = ft_strcat(args.dest, args.src);
}

static bool assert_strcat_result(StrcatArgs& args) {
	return args.dest && args.expected == args.dest;
}

static void	test_strcat_std(const std::vector<std::string>& test_strings) {
	char dest[100];

	memset(dest, 0, sizeof(dest));
	for (size_t i = 0; i < test_strings.size(); ++i) {
		strcpy(dest, test_strings[i].c_str());

		for (size_t j = 0; j < test_strings.size(); ++j) {
			std::string expected = std::string(dest) + test_strings[j];
			StrcatArgs args{dest, test_strings[j].c_str(), expected};

			run_test("ft_strcat(\"" + test_strings[i] + "\", \"" + test_strings[j] + "\")",
				[&]() { test_strcat_runner(args); },
				[&]() { return assert_strcat_result(args); },
				NO_SEGV);
		}
	}
}

static void	test_strcat_null() {
	char dest[1] = {0};

	run_test("ft_strcat(dest, NULL)",
		[&]() { ft_strcat(dest, nullptr); },
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
	char *dest = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dest) {
		std::cerr << "Failed to allocate memory for dest" << std::endl;
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE - 50, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		free(dest);
		return;
	}

	memset(dest, 'c', 50);
	memset(src, 'c', BIG_SIZE - 51);
	StrcatArgs args{dest, src, std::string(dest) + src};
	run_test("ft_strcat(dest[BIG_SIZE], src[BIG_SIZE - 50])",
		[&]() { test_strcat_runner(args); },
		[&]() { return assert_strcat_result(args); },
		NO_SEGV);

	args.dest[BIG_SIZE - 50] = '\0';
	src[49] = '\0';
	args.src = src;
	run_test("ft_strcat(dest[BIG_SIZE], src[50])",
		[&]() { test_strcat_runner(args); },
		[&]() { return assert_strcat_result(args); },
		NO_SEGV);

	free(src);
	free(dest);
}
