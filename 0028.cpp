/*
 * 28. Implement strStr()
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * Clarification:
 * What should we return when needle is an empty string? 
 * This is a great question to ask during an interview.
 * For the purpose of this problem, we will return 0 when needle is an empty string. 
 * This is consistent to C's strstr() and Java's indexOf().
 */

#include <string>

class Solution0028 {
public:
	static int str_str(std::string haystack, std::string needle) {
		if (needle.size() > haystack.size())
			return -1;

		for (auto i = 0; i <= haystack.size() - needle.size(); i++) {
			auto j = 0;
			for (j = 0; j < needle.size(); j++)
				if (needle[j] != haystack[j + i])
					break;
			if (j == needle.size())
				return i;
		}
		return -1;
	}
};
