/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/07 12:16:50 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

int	main() {
	std::vector<std::string> test_strings = {
		"Hello, World!",
		"lorem ipsum dolor sit amet",
		"test",
		"3 + 3 = 9",
		"\211\212",
		"",
	};

	std::cout << "\033[1;36m" << "Libft Unit Tests" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;

	std::cout << "\033[1;35m" << "String Functions" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;

	test_strcat(test_strings);
	test_strchr(test_strings);

	return (0);
}
