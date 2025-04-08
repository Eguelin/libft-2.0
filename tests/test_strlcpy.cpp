/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 11:13:59 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrlcpyArgs {
	char		*dst;
	char		*dst_ref;
	const char	*src;
	size_t		dst_size;
	size_t		result;
	size_t		result_ref;
};

static void	test_strlcpy_std(const std::vector<std::string>& test_strings);
static void	test_strlcpy_null();
static void	test_strlcpy_big();

void	test_strlcpy(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strlcpy" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strlcpy_std(test_strings);
	test_strlcpy_null();
	test_strlcpy_big();
}

static void	test_strlcpy_runner(StrlcpyArgs& args) {
	args.result = ft_strlcpy(args.dst, args.src, args.dst_size);
}

static bool assert_strlcpy_result(StrlcpyArgs& args) {
	return (args.result == args.result_ref && strcmp(args.dst, args.dst_ref) == 0);
}

static void	test_strlcpy_std(const std::vector<std::string>& test_strings) {
	char	dst[100];
	char	dst_ref[100];

	for (size_t i = 0; i < test_strings.size(); ++i) {
		StrlcpyArgs args{dst, dst_ref, test_strings[i].c_str(),
			test_strings[i].size(), 0, 0};

		args.result_ref = strlcpy(args.dst_ref, args.src, args.dst_size);
		run_test("ft_strlcpy(dest, \"" + test_strings[i] + "\", " + std::to_string(args.dst_size) + ")",
			[&]() { test_strlcpy_runner(args); },
			[&]() { return assert_strlcpy_result(args); },
			NO_SEGV);
	}

	for (size_t i = 0; i < 16; ++i) {
		StrlcpyArgs args{dst, dst_ref, "Hello word!", i, 0, 0};

		dst[6] = '\0';
		dst_ref[6] = '\0';
		args.result_ref = strlcpy(args.dst_ref, args.src, args.dst_size);
		run_test("ft_strlcpy(dest, \"Hello word!\", " + std::to_string(i) + ")",
			[&]() { test_strlcpy_runner(args); },
			[&]() { return assert_strlcpy_result(args); },
			NO_SEGV);
	}
}

static void	test_strlcpy_null() {
	char	str[1];

	run_test("ft_strlcpy(NULL, \"\", 0)",
		[]() { ft_strlcpy(nullptr, "", 0); },
		[]() { return true; },
		NO_SEGV);

	run_test("ft_strlcpy(NULL, \"test\", 2)",
		[]() { ft_strlcpy(nullptr, "test", 2); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strlcpy(str, NULL, 0)",
		[&] { ft_strlcpy(str, nullptr, 0); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strlcpy(NULL, NULL, 0)",
		[]() { ft_strlcpy(nullptr, nullptr, 0); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strlcpy_big() {
	char *dst = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst) {
		std::cerr << "Failed to allocpye memory for dst" << std::endl;
		return;
	}

	char *dst_ref = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst_ref) {
		std::cerr << "Failed to allocpye memory for dst_ref" << std::endl;
		free(dst);
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocpye memory for src" << std::endl;
		free(dst);
		free(dst_ref);
		return;
	}

	memset(src, 'c', BIG_SIZE - 1);
	StrlcpyArgs	args{dst, dst_ref, src, BIG_SIZE, 0, 0};
	args.result_ref = strlcpy(args.dst_ref, args.src, args.dst_size);
	run_test("ft_strlcpy(dst[BIG_SIZE], src[BIG_SIZE])",
		[&]() { test_strlcpy_runner(args); },
		[&]() { return assert_strlcpy_result(args); },
		NO_SEGV);

	free(src);
	free(dst);
	free(dst_ref);
}
