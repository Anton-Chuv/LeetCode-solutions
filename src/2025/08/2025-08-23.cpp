#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int result = INT_MAX;
        result = findMinSum(grid);
        reverse(grid.begin(), grid.end());
        for (int i = 0; i < grid.size(); i++) {
            reverse(grid[i].begin(), grid[i].end());
        }
        result = min(result, findMinSum(grid));
        return result;
    }
private:
    int findMinSum(vector<vector<int>>& grid) {

        int sumMin = INT_MAX;

        for (int i = 1; i < grid.size(); i++) { // check every first split for y
            vector<vector<vector<int>>> grids;
            vector<vector<vector<int>>> g = this->split(grid, i, 0);
            grids.push_back(vector<vector<int>>(g[0]));
            grids.push_back(vector<vector<int>>(g[1]));
            grids.push_back({});
            grids.push_back({});
            for (int j = 1; j < grids[1].size(); j++) { // check every second split for y
                g = this->split(grids[1], j, 0);
                grids[2] = g[0];
                grids[3] = g[1];
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    if (k == 1) continue;
                    sum += this->minimumArea(grids[k]);
                }
                sumMin = min(sumMin, sum);
            }
            for (int j = 1; j < grids[1][0].size(); j++) { // check every second split for x
                g = this->split(grids[1], 0, j);
                grids[2] = g[0];
                grids[3] = g[1];
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    if (k == 1) continue;
                    sum += this->minimumArea(grids[k]);
                }
                sumMin = min(sumMin, sum);
            }

        }
        for (int i = 1; i < grid[0].size(); i++) { // check every first split for x
            vector<vector<vector<int>>> grids;
            vector<vector<vector<int>>> g = this->split(grid, 0, i);
            grids.push_back(vector<vector<int>>(g[0]));
            grids.push_back(vector<vector<int>>(g[1]));
            grids.push_back({});
            grids.push_back({});
            for (int j = 1; j < grids[1].size(); j++) { // check every second split for y
                g = this->split(grids[1], j, 0);
                grids[2] = g[0];
                grids[3] = g[1];
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    if (k == 1) continue;
                    sum += this->minimumArea(grids[k]);
                }
                sumMin = min(sumMin, sum);
            }
            for (int j = 1; j < grids[1][0].size(); j++) { // check every second split for x
                g = this->split(grids[1], 0, j);
                grids[2] = g[0];
                grids[3] = g[1];
                int sum = 0;
                for (int k = 0; k < 4; k++) {
                    if (k == 1) continue;
                    sum += this->minimumArea(grids[k]);
                }
                sumMin = min(sumMin, sum);
            }
        }

        return sumMin;
    }
    int minimumArea(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int left = cols - 1;
        int top = rows - 1;
        int right = 0;
        int bottom = -1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    if (i < top) top = i;
                    if (i > bottom) bottom = i;
                    if (j < left) left = j;
                    if (j > right) right = j;
                }
            }
        }
        if (bottom == -1) return 0;
        return (right - left + 1) * (bottom - top + 1);
    }
    vector<vector<vector<int>>> split(vector<vector<int>>& grid, int row, int col) {
        if (col == 0) {
            vector<vector<int>> grid1(grid.begin(), grid.begin() + row);
            vector<vector<int>> grid2(grid.begin() + row, grid.end());
            return {grid1, grid2};
        }
        if (row == 0) {
            vector<vector<int>> grid1;
            vector<vector<int>> grid2;
            for (int i = 0; i < grid.size(); i++) {
                grid1.push_back(vector<int>(grid[i].begin(), grid[i].begin() + col));
                grid2.push_back(vector<int>(grid[i].begin() + col, grid[i].end()));
            }
            return {grid1, grid2};
        }
        return {{}, {}};
    }

};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1}};

    cout << solution.minimumSum(grid);

    return 0;
}
