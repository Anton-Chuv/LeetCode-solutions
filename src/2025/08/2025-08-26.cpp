class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxSquarDiagonal = 0;
        int maxArea = 0;
        for (vector<int> x: dimensions) {
            int squarDiag = x[0] * x[0] + x[1] * x[1];
            int area = x[0] * x[1];
            if (maxSquarDiagonal < squarDiag ||
                maxSquarDiagonal == squarDiag && maxArea <= area) {
                maxArea = area;
                maxSquarDiagonal = squarDiag;
            }
        }
        return maxArea;
    }
};
