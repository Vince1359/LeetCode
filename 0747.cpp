/*
 * 747. Largest Number At Least Twice of Others
 * In a given integer array nums, there is always exactly one largest element.
 * Find whether the largest element in the array is at least twice as much as 
 * every other number in the array.
 * If it is, return the index of the largest element, otherwise return -1.
 * 
 * Example 1:
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 * 
 * Example 2:
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 */

#include <vector>
#include <algorithm>

class Solution {
public:
	int dominant_index(std::vector<int>& nums) const
	{
		const auto max_num = *max_element(nums.begin(), nums.end());
		auto res = -1;
		for (auto i = 0; i < nums.size(); i++)
			if (nums[i] != max_num) {
				if (max_num < 2 * nums[i])
					return -1;
			}
			else
				res = i;
		return res;
	}
};
