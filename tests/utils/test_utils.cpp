/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:27:51 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 12:15:20 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

sigjmp_buf	env;

void	catch_segfault() {
	struct sigaction sa{};
	sa.sa_handler = [](int) { siglongjmp(env, 1); };
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGSEGV, &sa, nullptr);
}

void	default_sigaction() {
	struct sigaction sa{};
    sa.sa_handler = SIG_DFL;
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, nullptr);
}

void	run_test(const std::string& label,
	std::function<void()> test_func,
	std::function<bool()> assert_func,
	SegvExpectation expect_segv)
{
	catch_segfault();
	if (sigsetjmp(env, 1) == 0) {
		test_func();
		if (expect_segv == EXPECT_SEGV)
			std::cout << "\033[33m[WARN]\033[0m ";
		else if (!assert_func || assert_func())
			std::cout << "\033[32m[OK]\033[0m ";
		else
			std::cout << "\033[31m[KO]\033[0m ";
	}
	else {
		if (expect_segv == EXPECT_SEGV)
			std::cout << "\033[32m[OK]\033[0m ";
		else
			std::cout << "\033[31m[SEGV]\033[0m ";
	}
	std::cout << label << std::endl;
	default_sigaction();
}

std::vector<std::string> gen_substrings(const std::vector<std::string> &test_strings) {
	std::vector<std::string>	substrings;
	size_t						start = 0;
	size_t 						size = 0;
	std::string					substring;

	srand(4343);
	for (size_t i = 0; i < test_strings.size(); ++i) {
		if (test_strings[i].size() > 0) {
			start = rand() % test_strings[i].size();
			size = rand() % (test_strings[i].size() - start + 1);
			substring = test_strings[i].substr(start, size);
		}
		else
			substring = test_strings[i];
		substrings.push_back(substring);
	}
	return substrings;
}
