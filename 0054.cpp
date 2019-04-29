#include <vector>

class Solution {
public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
		N = matrix.size();
		if (N == 0)
			return {};

		M = matrix[0].size();
		if (M == 0)
			return {};

		std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
		int curd = 0, curx = 0, cury = 0;
		std::vector<int> res;
		while (res.size() < N * M) {

			if (!visited[curx][cury]) {
				res.push_back(matrix[curx][cury]);
				visited[curx][cury] = true;
			}

			int nextx = curx + d[curd][0];
			int nexty = cury + d[curd][1];
			if (inArea(nextx, nexty) && !visited[nextx][nexty]) {
				curx = nextx;
				cury = nexty;
			}
			else
				curd = (curd + 1) % 4;
		}
		return res;
	}
private:
	int d[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	int N, M;

	bool inArea(int x, int y) {
		return x >= 0 && x < N && y >= 0 && y < M;
	}
};
