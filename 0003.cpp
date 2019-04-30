/*
 * 3. Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <string>
#include <algorithm>

class Solution {
public:
	int length_of_longest_substring(std::string s) const
	{
		int last[128];
		memset(last, -1, sizeof(last));

		auto l = 0, r = -1;
		auto res = 0;
		while (r + 1 < s.size()) {
			r++;
			if (last[s[r]] != -1)
				l = std::max(l, last[s[r]] + 1);

			res = std::max(res, r - l + 1);
			last[s[r]] = r;
		}
		return res;
	}
};
