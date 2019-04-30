/*
 * 67. Add Binary
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */

#include <string>

class Solution0067 {
public:
	static std::string add_binary(std::string a, std::string b) {
		auto res = a.size() > b.size() ? a : b;
		auto adder = a.size() > b.size() ? b : a;

		int index = res.size() - 1;
		for (int i = adder.size() - 1; i >= 0; i--) {
			res[index] += adder[i] - '0';
			index--;
		}
		for (int i = res.size() - 1; i > 0; i--) {
			if (res[i] > '1') {
				res[i - 1] += 1;
				res[i] = '0' + (res[i] - '0') % 2;
			}
		}
		if (res[0] > '1') {
			res[0] = '0' + (res[0] - '0') % 2;
			res = '1' + res;
		}
		return res;
	}
};
