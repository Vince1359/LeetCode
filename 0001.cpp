#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++) {

			int complement = target - nums[i];
			if (record.find(complement) != record.end()) {
				int res[] = { i, record[complement] };
				return vector<int>(res, res + 2);
			}

			record[nums[i]] = i;
		}
		throw invalid_argument("the input has no solution");
	}
};