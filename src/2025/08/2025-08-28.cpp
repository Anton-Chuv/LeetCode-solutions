#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> valArrs = {{}, {}};
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            valArrs[0].clear();
            valArrs[1].clear();
            for (int j = 0; j + i < n; j++) {
                valArrs[0].push_back(grid[j + i][j]);
                valArrs[1].push_back(grid[j][j + i]);
            }
            sort(valArrs[0].begin(), valArrs[0].end(), std::greater<>());
            sort(valArrs[1].begin(), valArrs[1].end());
            for (int j = 0; j + i < n; j++) {
                grid[j][j + i] = valArrs[1][j];
                grid[j + i][j] = valArrs[0][j];
            }
        }
        return grid;

    }
};
