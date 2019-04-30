/*
 * 498. Diagonal Traverse
 * Given a matrix of M x N elements (M rows, N columns), 
 * return all elements of the matrix in diagonal order as shown in the below image.
 * 
 * Example:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 */

#include <vector>

class Solution0498 {
public:
	static std::vector<int> find_diagonal_order(std::vector<std::vector<int>>& matrix) {
		std::vector<int> res;

		n_ = matrix.size();
		if (n_ == 0)
			return res;
		m_ = matrix[0].size();

		auto x = 0, y = 0;
		int next_x, next_y;
		auto up = true;
		while (true) {
			res.push_back(matrix[x][y]);

			if (up)
				next_x = x - 1, next_y = y + 1;
			else
				next_x = x + 1, next_y = y - 1;

			if (in_area(next_x, next_y))
				x = next_x, y = next_y;
			else if (up) {
				if (in_area(x, y + 1))
					y++;
				else
					x++;
				up = false;
			}
			else {
				if (in_area(x + 1, y))
					x++;
				else
					y++;
				up = true;
			}

			if (!in_area(x, y))
				break;
		}

		return res;
	}
private:
	static int n_, m_;

	static bool in_area(const int x, const int y)
	{
		return x >= 0 && x < n_ && y >= 0 && y < m_;
	}
};
