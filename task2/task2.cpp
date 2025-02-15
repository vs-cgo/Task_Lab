#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		return 0;
	}
	std::ifstream file(argv[1]);	
	if (!file.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return 0;
	}

	float x = 0, y = 0, r = 0;
	file >> x >> y >> r;
	if ((file.fail() && !file.eof()) || file.bad()) {
		std::cout << "ошибка чтения файла" << std::endl;
		return 0;
	}
	
	file.close();
	file.clear();
	file.open(argv[2]);
	if (!file.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return 0;
	}
	
	for (float a = 0, b = 0; file >> a >> b, file; ) {
		float dist = std::sqrt((a - x) * (a - x)  + (b - y) * (b - y));
		int res = dist > r ? 2 : dist < r ? 1 : 0;
		std::cout << res << std::endl;
	}
	if (file.bad() || (file.fail() && !file.eof())) {
		std::cout << "ошибка чтения файла" << std::endl;
		return 0;
	}
	file.close();
	return 0;
}
