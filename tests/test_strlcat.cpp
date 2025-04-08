/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/08 11:13:59 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

struct	StrlcatArgs {
	char		*dst;
	char		*dst_ref;
	const char	*src;
	size_t		dst_size;
	size_t		result;
	size_t		result_ref;
};

static void	test_strlcat_std(const std::vector<std::string>& test_strings);
static void	test_strlcat_null();
static void	test_strlcat_big();

void	test_strlcat(std::vector<std::string> test_strings) {
	std::cout << "\033[1;34m" << "ft_strlcat" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;
	test_strlcat_std(test_strings);
	test_strlcat_null();
	test_strlcat_big();
}

static void	test_strlcat_runner(StrlcatArgs& args) {
	args.result = ft_strlcat(args.dst, args.src, args.dst_size);
}

static bool assert_strlcat_result(StrlcatArgs& args) {
	return (args.result == args.result_ref && strcmp(args.dst, args.dst_ref) == 0);
}

static void	test_strlcat_std(const std::vector<std::string>& test_strings) {
	char	dst[100];
	char	dst_ref[100];
	size_t size;

	for (size_t i = 0; i < test_strings.size(); ++i) {
		size = test_strings[i].size() + 1;

		strcpy(dst, test_strings[i].c_str());
		strcpy(dst_ref, test_strings[i].c_str());
		for (size_t j = 0; j < test_strings.size(); ++j) {
			StrlcatArgs args{dst, dst_ref, test_strings[j].c_str(),
				test_strings[i].size() + test_strings[j].size() / 2, 0, 0};

			dst[size] = '\0';
			dst_ref[size] = '\0';
			args.result_ref = strlcat(args.dst_ref, args.src, args.dst_size);
			run_test("ft_strlcat(\"" + test_strings[i] + "\", \"" + test_strings[j] + "\", " + std::to_string(args.dst_size) + ")",
				[&]() { test_strlcat_runner(args); },
				[&]() { return assert_strlcat_result(args); },
				NO_SEGV);
		}
	}

	strcpy(dst, "Hello ");
	strcpy(dst_ref, "Hello ");
	for (size_t i = 0; i < 16; ++i) {
		StrlcatArgs args{dst, dst_ref, "word!", i, 0, 0};

		dst[6] = '\0';
		dst_ref[6] = '\0';
		args.result_ref = strlcat(args.dst_ref, args.src, args.dst_size);
		run_test("ft_strlcat(\"Hello \", \"word!\", " + std::to_string(i) + ")",
			[&]() { test_strlcat_runner(args); },
			[&]() { return assert_strlcat_result(args); },
			NO_SEGV);
	}
}

static void	test_strlcat_null() {
	char	str[1];

	run_test("ft_strlcat(NULL, \"\", 0)",
		[]() { ft_strlcat(nullptr, "", 0); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strlcat(str, NULL, 0)",
		[&] { ft_strlcat(str, nullptr, 0); },
		[]() { return false; },
		EXPECT_SEGV);

	run_test("ft_strlcat(NULL, NULL, 0)",
		[]() { ft_strlcat(nullptr, nullptr, 0); },
		[]() { return false; },
		EXPECT_SEGV);
}

static void	test_strlcat_big() {
	char *dst = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst) {
		std::cerr << "Failed to allocate memory for dst" << std::endl;
		return;
	}

	char *dst_ref = static_cast<char *>(calloc(BIG_SIZE, sizeof(char)));
	if (!dst_ref) {
		std::cerr << "Failed to allocate memory for dst_ref" << std::endl;
		free(dst);
		return;
	}

	char *src = static_cast<char *>(calloc(BIG_SIZE - 50, sizeof(char)));
	if (!src) {
		std::cerr << "Failed to allocate memory for src" << std::endl;
		free(dst);
		free(dst_ref);
		return;
	}

	memset(dst, 'c', 50);
	memset(dst_ref, 'c', 50);
	memset(src, 'c', BIG_SIZE - 51);
	StrlcatArgs	args{dst, dst_ref, src, BIG_SIZE, 0, 0};
	args.result_ref = strlcat(args.dst_ref, args.src, args.dst_size);
	run_test("ft_strlcat(dst[BIG_SIZE], src[BIG_SIZE - 50])",
		[&]() { test_strlcat_runner(args); },
		[&]() { return assert_strlcat_result(args); },
		NO_SEGV);

	args.dst[BIG_SIZE - 50] = '\0';
	dst_ref[BIG_SIZE - 50] = '\0';
	src[49] = '\0';
	args.result_ref = strlcat(args.dst_ref, args.src, args.dst_size);
	run_test("ft_strlcat(dst[BIG_SIZE], src[50])",
		[&]() { test_strlcat_runner(args); },
		[&]() { return assert_strlcat_result(args); },
		NO_SEGV);

	free(src);
	free(dst);
	free(dst_ref);
}
