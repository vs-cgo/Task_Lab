#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

int getID(std::string &s);
std::string getValue(std::string &str);
std::unordered_map<int, std::string> getResult(std::string str);

int main(int argc, char *argv[]) {
	if (argc != 4) {
		return 0;
	}
	std::unordered_map<int, std::string> res = getResult(argv[1]);
	if (res.size() == 0) {
		return 0;
	}
	
	std::ifstream value(argv[2]);	
	if (!value.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return 0;
	}
	
	std::ofstream file(argv[3]);
	if (!file.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return 0;
	}
	
	int id = 0;
	std::string s;
	while (std::getline(value, s)) {
		if (s.find("\"id\":") != std::string::npos) {
			id = getID(s);
		} else if (s.find("\"value\":") != std::string::npos) {
			int ind = s.find_first_of(":");
			int last = s.find_last_of("\"");
			if(res[id] != "") {
				s = s.substr(0, ind+1) + res[id] + s.substr(last+1);
			}
		}
		file << s << '\n';
	}
	return 0;
}

int getID(std::string &s) {
	int res = 0;
	int first = s.find_first_of("0123456789");
	int last  = s.find_last_of("0123456789");
	while (first <= last) {
		res = res * 10 + s[first++] - '0';
	}
	return res;
}
std::string getValue(std::string &str) {
	int start = str.find_first_of(":");
	return str.substr(start+1);
}
std::unordered_map<int, std::string> getResult(std::string str) {
	std::unordered_map<int, std::string> m;
	std::ifstream file(str);
	if (!file.is_open()) {
		std::cout << "ошибка открытия файла" << std::endl;
		return m;
	};
	
	std::string s;
	int id = 0;
	while(std::getline(file, s)) {
		if(s.find("\"id\":") != std::string::npos) {
			id = getID(s);
		} else if (s.find("\"value\":") != std::string::npos) {
			m[id] = getValue(s); 
		}
	}
	return m;
}
