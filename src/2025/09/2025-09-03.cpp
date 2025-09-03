#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;

        vector< vector<int> > sortedXPoints = points;
        sort(sortedXPoints.begin(), sortedXPoints.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            }
        );
        for (int i = 0; i < sortedXPoints.size(); i++) {
            for (int j = i + 1; j < sortedXPoints.size(); j++) {
                if (sortedXPoints[i][1] >= sortedXPoints[j][1]) {
                    int k;
                    for (k = i + 1; k < j; k++) {
                        if (sortedXPoints[i][1] >= sortedXPoints[k][1] &&
                        sortedXPoints[j][1] <= sortedXPoints[k][1]) {
                            break;
                        }
                    }
                    if (k == j)
                        count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}};
    int result = solution.numberOfPairs(points);
    cout << "Number of pairs: " << result << endl;
    return 0;
}
