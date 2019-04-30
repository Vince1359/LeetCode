/*
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a 
 * specific target. You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */

#include <vector>
#include <unordered_map>
#include <stdexcept>

class Solution0001 {
public:
	static std::vector<int> two_sum(std::vector<int>& nums, const int target) {
		std::unordered_map<int, int> record;
		for (auto i = 0; i < nums.size(); i++) {
			auto complement = target - nums[i];
			if (record.find(complement) != record.end()) {
				int res[] = { i, record[complement] };
				return std::vector<int>(res, res + 2);
			}
			record[nums[i]] = i;
		}
		throw std::invalid_argument("the input has no solution");
	}
};