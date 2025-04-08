/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 17:25:50 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrlenArgs {
	const char	*s;
	size_t		result;
};

static void	test_strlen_std(const std::vector<std::string>& test_strings);
static void	test_strlen_null();
static void	test_strlen_big();

void	test_strlen(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strlen" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strlen_std(test_strings);
	test_strlen_null();
	test_strlen_big();
}

static void	test_strlen_runner(StrlenArgs& args) {
	args.result = ft_strlen(args.s);
}

static bool assert_strlen_result(StrlenArgs& args) {
	return (args.result == strlen(args.s));
}

static void	test_strlen_std(const std::vector<std::string>& test_strings) {
	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrlenArgs args{test_strings[i].c_str(), 0};

		run_test("ft_strlen(\"" + test_strings[i] + "\")",
			[&]() { test_strlen_runner(args); },
			[&]() { return assert_strlen_result(args); },
			NO_SEGV);
	}
}

static void	test_strlen_null() {
	run_test("ft_strlen(NULL)",
		[]() { ft_strlen(nullptr); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strlen_big() {
	char *s = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!s) {
		std::cerr << "Failed to alloene memory for s" << std::endl;
		return;
	}

	memset(s, 'c', BIG_SIZE - 1);
	StrlenArgs	args{s, 0};
	run_test("ft_strlen(s[BIG_SIZE])",
		[&]() { test_strlen_runner(args); },
		[&]() { return assert_strlen_result(args); },
		NO_SEGV);

	free(s);
}
