/*
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * Note:
 * All given inputs are in lowercase letters a-z.
 */

#include <string>
#include <vector>

class Solution0014 {
public:
	static std::string longest_common_prefix(std::vector<std::string>& strs) {
		if (strs.empty()) return "";
		for (auto i = 0; i < strs[0].length(); i++) {
			const auto c = strs[0].at(i);
			for (auto j = 1; j < strs.size(); j++) {
				if (i == strs[j].length() || strs[j].at(i) != c)
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};
