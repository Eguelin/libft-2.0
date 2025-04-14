#include "test.hpp"

void	test_str(bool bigstr, const std::vector<std::string> &functests) {
	const std::vector<std::string> &test_strings = {
		"Hello, World!",
		"lorem ipsum dolor sit amet",
		"test",
		"3 + 3 = 9",
		"\211\212",
		"",
	};
	std::map<std::string, std::function<void(const std::vector<std::string> &, bool)>> tests = {
		{"strcat", test_strcat},
		{"strchr", test_strchr},
		{"strcmp", test_strcmp},
		{"strcpy", test_strcpy},
		{"strdup", test_strdup},
		{"strlcat", test_strlcat},
		{"strlcpy", test_strlcpy},
		{"strlen", test_strlen},
		{"strncmp", test_strncmp},
		{"strndup", test_strndup},
		{"strnstr", test_strnstr}
	};

	std::cout << "\033[1;35m" << "String Functions" << "\033[0m" << std::endl;
	std::cout << "======================" << std::endl;

	if (functests.size() > 0) {
		for (std::vector<std::string>::const_iterator it = functests.begin(); it != functests.end(); ++it) {
			if (tests.find(*it) != tests.end())
				tests[*it](test_strings, bigstr);
		}
	} else {
		for (std::map<std::string, std::function<void(const std::vector<std::string> &, bool)>>::iterator it = tests.begin(); it != tests.end(); ++it) {
			it->second(test_strings, bigstr);
		}
	}
}
