#include <string>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		std::string res = a.size() > b.size() ? a : b;
		std::string adder = a.size() > b.size() ? b : a;

		int index = res.size() - 1;
		for (int i = adder.size() - 1; i >= 0; i--) {
			res[index] += adder[i] - '0';
			index--;
		}

		for (int i = res.size() - 1; i > 0; i--)
			if (res[i] > '1') {
				res[i - 1] += 1;
				res[i] = '0' + (res[i] - '0') % 2;
			}

		if (res[0] > '1') {
			res[0] = '0' + (res[0] - '0') % 2;
			res = '1' + res;
		}
		return res;
	}
};
