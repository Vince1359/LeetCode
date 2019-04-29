#include <numeric>
#include <vector>

class Solution {
public:
	int pivotIndex(std::vector<int>& nums) {
		if (nums.size() == 0)
			return -1;

		int sum = std::accumulate(nums.begin(), nums.end(), 0);

		int leftSum = 0;
		for (int i = 0; i < nums.size(); i++)
			if (leftSum == sum - leftSum - nums[i])
				return i;
			else
				leftSum += nums[i];

		return -1;
	}
};
