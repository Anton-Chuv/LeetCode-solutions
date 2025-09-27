class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int len = points.size();
        for (int i = 0; i < len - 2; i++) {
            for (int j = i+1; j < len - 1; j++) {
                for (int k = j+1; k < len; k++) {
                    double area = abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    ) * 1.0 / 2.0;
                    if (area > maxArea) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
