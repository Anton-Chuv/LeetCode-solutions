from typing import List


class Solution:
    def reverseSubmatrix(
        self, grid: List[List[int]], x: int, y: int, k: int
    ) -> List[List[int]]:
        for i in range(k // 2):
            for j in range(y, y + k):
                grid[x + i][j], grid[x + k - i - 1][j] = (
                    grid[x + k - i - 1][j],
                    grid[x + i][j],
                )
        return grid


if __name__ == "__main__":
    sol = Solution()
    grid = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    print(sol.reverseSubmatrix(grid, 1, 0, 3))
