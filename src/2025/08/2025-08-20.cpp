#include <iostream>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    count++;
                    bool flag = true;
                    for (int k = 1; i + k < rows && j + k < cols; k++) {
                        for (int l = 0; l <= k; l++) {
                            if (matrix[i + k][j + l] == 0 || matrix[i + l][j + k] == 0) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << solution.countSquares(matrix) << endl;
    return 0;
}
