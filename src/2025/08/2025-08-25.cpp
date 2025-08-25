#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> out;
        int width = mat.size();
        int height = mat[0].size();
        int i = 0;
        int j = 0;
        for (int k = 0; k < width + height - 1; k++) {
            if (k % 2 == 1){
                while (j >= 0 && i < width) {
                    out.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if (i == width) {
                    i--;
                    j += 2;
                }
                else {
                    j++;
                }

            }
            if (k % 2 == 0) {
                while (j < height && i >= 0) {
                    out.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if (j == height) {
                    j--;
                    i += 2;
                }
                else {
                    i++;
                }
            }

        }
        return out;
    }
};
