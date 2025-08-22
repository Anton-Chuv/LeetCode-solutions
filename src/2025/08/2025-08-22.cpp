#include <iostream>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        bool flag = true;
        int lenX = grid.size();
        int lenY = grid[0].size();
        int minX, minY, maxX, maxY;

        for (int i = 0; i < lenX && flag; i++)
            for (int j = 0; j < lenY; j++)
                if (grid[i][j] == 1) {
                    minY = i;
                    flag = false;
                    break;
                }

        flag = true;
        for (int i = lenX - 1; i >= 0 && flag; i--)
            for (int j = 0; j < lenY; j++)
                if (grid[i][j] == 1) {
                    maxY = i;
                    flag = false;
                    break;
                }

        flag = true;
        for (int i = 0; i < lenY && flag; i++)
            for (int j = 0; j < lenX; j++)
                if (grid[j][i] == 1) {
                    minX = i;
                    flag = false;
                    break;
                }

        flag = true;
        for (int i = lenY - 1; i >= 0 && flag; i--)
            for (int j = 0; j < lenX; j++)
                if (grid[j][i] == 1) {
                    maxX = i;
                    flag = false;
                    break;
                }

        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
