/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/16 15:17:58 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	SubstrArgs {
	char			*result;
	unsigned int	start;
	size_t			len;
	const char		*src;
};

static void	test_substr_std(const std::vector<std::string> &test_strings);
static void	test_substr_null();
static void	test_substr_big();

void	test_substr(const std::vector<std::string> &test_strings, bool bigstr) {
	std::cout << "\033[1;34m" << "ft_substr" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_substr_std(test_strings);
	test_substr_null();
	if (bigstr)
		test_substr_big();
}

static void	test_substr_runner(SubstrArgs &args) {
	args.result = ft_substr(args.src, args.start, args.len);
	if (args.result == nullptr) {
		std::cerr << "Failed to allocate memory for result" << std::endl;
		return;
	}
}

static bool assert_substr_result(SubstrArgs &args) {
	std::string	result_ref;

	try {
		result_ref = std::string(args.src).substr(args.start, args.len);
	}
	catch (const std::out_of_range &e) {
		result_ref = "";
	}
	return (args.result != nullptr && args.src != nullptr && args.result != args.src &&
		strcmp(args.result, result_ref.c_str()) == 0);
}

static void	test_substr_std(const std::vector<std::string> &test_strings) {
	size_t start = 0;
	size_t size = 0;

	srand(4343);
	for (size_t i = 0; i < test_strings.size(); ++i) {
		if (test_strings[i].size() > 0) {
			start = rand() % test_strings[i].size();
			size = rand() % (test_strings[i].size() - start + 1);
		}
		else
			start = size = 0;
		SubstrArgs args{nullptr, static_cast<unsigned int>(start), size, test_strings[i].c_str()};
		run_test("ft_substr(\"" + test_strings[i] + "\"" + ", " + std::to_string(start) + ", " + std::to_string(size) + ")",
			[&]() { test_substr_runner(args); },
			[&]() { return assert_substr_result(args); },
			NO_SEGV);
		free(args.result);
	}

	for (size_t i = 0; i < test_strings[0].size() + 3; ++i) {
		for (size_t j = 0; j < test_strings[0].size(); ++j) {
			SubstrArgs args{nullptr, static_cast<unsigned int>(i), j, test_strings[0].c_str()};
			run_test("ft_substr(\"" + test_strings[0] + "\"" + ", " + std::to_string(i) + ", " + std::to_string(j) + ")",
				[&]() { test_substr_runner(args); },
				[&]() { return assert_substr_result(args); },
				NO_SEGV);
			free(args.result);
		}
	}
}

static void	test_substr_null() {
	run_test("ft_substr(NULL)",
		[&]() { ft_substr(nullptr, 0, 0); },
		[]() { return true; },
		NO_SEGV);
}

static void	test_substr_big() {
	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		return;
	}

	memset(src, 'a', BIG_SIZE - 1);
	SubstrArgs args{nullptr, 0, BIG_SIZE - 1, src};
	run_test("ft_substr(str[BIG_SIZE])",
		[&]() { test_substr_runner(args); },
		[&]() { return assert_substr_result(args); },
		NO_SEGV);

	free(args.result);
	free(src);
}
