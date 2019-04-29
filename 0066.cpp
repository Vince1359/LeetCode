#include <vector>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits) {
		digits[digits.size() - 1] ++;
		for (int i = digits.size() - 1; i >= 1; i--)
			if (digits[i] == 10) {
				digits[i] = 0;
				digits[i - 1] ++;
			}

		if (digits[0] == 10) {
			digits[0] = 0;
			digits.insert(digits.begin(), 1);
		}

		return digits;
	}
};
