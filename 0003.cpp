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
