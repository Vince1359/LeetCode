/*
 * 54. Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns), 
 * return all elements of the matrix in spiral order.
 * 
 * Example 1:
 * Input:
 * [
 *   [ 1, 2, 3 ],
 *   [ 4, 5, 6 ],
 *   [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * Example 2:
 * Input:
 * [
 *   [1, 2, 3, 4],
 *   [5, 6, 7, 8],
 *   [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include <vector>

class Solution0054 {
public:
	std::vector<int> spiral_order(std::vector<std::vector<int>>& matrix) {
		n_ = matrix.size();
		if (n_ == 0)
			return {};

		m_ = matrix[0].size();
		if (m_ == 0)
			return {};

		std::vector<std::vector<bool>> visited(n_, std::vector<bool>(m_, false));
		auto curd = 0, curx = 0, cury = 0;
		std::vector<int> res;
		while (res.size() < n_ * m_) {

			if (!visited[curx][cury]) {
				res.push_back(matrix[curx][cury]);
				visited[curx][cury] = true;
			}

			const auto nextx = curx + d_[curd][0];
			const auto nexty = cury + d_[curd][1];
			if (in_area(nextx, nexty) && !visited[nextx][nexty]) {
				curx = nextx;
				cury = nexty;
			}
			else
				curd = (curd + 1) % 4;
		}
		return res;
	}
private:
	int d_[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int n_{}, m_{};

	bool in_area(const int x, const int y) const
	{
		return x >= 0 && x < n_ && y >= 0 && y < m_;
	}
};
