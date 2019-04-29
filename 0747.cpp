#include <vector>
#include <algorithm>

class Solution {
public:
	int dominantIndex(std::vector<int>& nums) {
		int maxNum = *max_element(nums.begin(), nums.end());
		int res = -1;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != maxNum) {
				if (maxNum < 2 * nums[i])
					return -1;
			}
			else
				res = i;
		return res;
	}
};
