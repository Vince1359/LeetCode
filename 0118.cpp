/*
 * 118. Pascal's Triangle
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * 
 * Example:
 * Input: 5
 * Output:
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 */

#include <vector>

class Solution {
public:
	static std::vector<std::vector<int>> generate(const int num_rows) {
		std::vector<std::vector<int>> res;
		if (num_rows <= 0)
			return res;

		res.push_back({ 1 });
		for (auto i = 1; i < num_rows; i++) {
			std::vector<int> row;
			row.push_back(1);
			for (auto j = 1; j < i; j++)
				row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
			row.push_back(1);
			res.push_back(row);
		}
		return res;
	}
};
