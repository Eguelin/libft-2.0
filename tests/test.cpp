/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:41:05 by eguelin           #+#    #+#             */
/*   Updated: 2025/04/14 10:55:47 by eguelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

static bool	getflag(int argc, char **argv);
static std::vector<std::string> getfunctests(int argc, char **argv);

int	main(int argc, char **argv) {
	// Check if the --bigstr flag is set
	bool 						bigstr = getflag(argc, argv);
	std::vector<std::string>	functests = getfunctests(argc, argv);


	std::cout << "\033[1;36m" << "Libft Unit Tests" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;

	test_str(bigstr, functests);

	std::cout << "======================" << std::endl;
	std::cout << "\033[1;36m" << "End of Tests" << "\033[0m" << std::endl;

	return (0);
}


static bool	getflag(int argc, char **argv) {
	if (argc < 2)
		return (0);
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "--bigstr") == 0)
			return (true);
		else if (strcmp(argv[i], "-b") == 0)
			return (true);
	}
	return (false);
}

static std::vector<std::string> getfunctests(int argc, char **argv) {
	std::vector<std::string> functests;
	if (argc < 2)
		return (functests);
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "--bigstr") == 0 || strcmp(argv[i], "-b") == 0)
			continue;
		functests.push_back(argv[i]);
	}
	return (functests);
}
