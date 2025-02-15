#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return 0;
	}
	
	std::ifstream file(argv[1]);	
	if (!file.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return 0;
	}
	
	std::vector<int> nums;
	for (int val = 0; file >> val, file;) {
		nums.push_back(val);
	}
	if (file.bad() || (file.fail() && !file.eof())) {
		std::cout << "ошибка чтения файла" << std::endl;
		return 0;
	}
	file.close();
	std::sort(nums.begin(), nums.end());
	int n = nums.size(), ans = 0;
	if (n == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}
	int mid = nums[n / 2];
	for (int &x : nums) {
		ans += std::abs(x - mid);
	}
	std::cout << ans << std::endl;
	return 0;
}
