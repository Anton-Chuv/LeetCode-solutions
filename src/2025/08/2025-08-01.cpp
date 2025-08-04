#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output = {{1}};
        for (int i = 1; i < numRows; i++) {
            output.push_back({1});
            for (int j = 1; j < i; j++) {
                int x = output[i-1][j-1] + output[i-1][j];
                output[i].push_back(x);
            }
            output[i].push_back(1);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rows = sol.generate(5);
    for (vector<int> row: rows) {
        for (int n: row)
            cout << n << ' ';
        cout << endl;

    }

    return 0;
}