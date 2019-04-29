#include <vector>

class Solution {
public:
	std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix) {
		std::vector<int> res;

		n = matrix.size();
		if (n == 0)
			return res;
		m = matrix[0].size();

		int x = 0, y = 0;
		int nextX, nextY;
		bool up = true;
		while (true) {
			res.push_back(matrix[x][y]);

			if (up)
				nextX = x - 1, nextY = y + 1;
			else
				nextX = x + 1, nextY = y - 1;

			if (inArea(nextX, nextY))
				x = nextX, y = nextY;
			else if (up) {
				if (inArea(x, y + 1))
					y++;
				else
					x++;
				up = false;
			}
			else {
				if (inArea(x + 1, y))
					x++;
				else
					y++;
				up = true;
			}

			if (!inArea(x, y))
				break;
		}

		return res;
	}
private:
	int n, m;

	bool inArea(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}
};
