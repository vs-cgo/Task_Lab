#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "неверное количество аргументов" << std::endl;
		return 0;
	}
	long long n = 0, m = 0;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	if (n < 1 || m < 1) {
		std::cout << "неверные аргументы" << std::endl;
		return 0;
	}
	std::string ans;
	ans += '1';
	for (long long i = m-1; i != 0; i = (i + m-1) % n) {
		ans += (i + 49);
	}
	std::cout << ans << std::endl;
	return 0;
}

long long atoi(char* str) {
	long long res = 0, sign = 1;
	if (*str == '-') {
		sign = -1;
		++str;
	} else if (*str == '+') {
		++str;
	}
	for (; *str != 0; ++str) {
		if(*str < 48 || * str > 57) return -1;
		res *= 10 + (*str - 48);
	}
	return res;
}
