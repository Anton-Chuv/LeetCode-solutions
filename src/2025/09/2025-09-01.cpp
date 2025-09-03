#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double maxRatio = 0.0;
        vector<pair<double, pair<int, int>>> ratios;

        for (const auto& cls : classes) {
            int passed = cls[0];
            int total = cls[1];
            double ratio = static_cast<double>(passed) / total;
            double delta = (passed + 1) / static_cast<double>(total + 1) - ratio;
            ratios.push_back({delta, {passed, total}});
            maxRatio += ratio;
        }

        make_heap(ratios.begin(), ratios.end(), less<pair<double, pair<int, int>>>());


        for (int i = 0; i < extraStudents; ++i) {
            maxRatio += ratios[0].first;
            pair<int, int> cls = ratios[0].second;
            int passed = cls.first;
            int total = cls.second;
            passed++;
            total++;
            double delta = (passed + 1) / static_cast<double>(total + 1) - static_cast<double>(passed) / total;
            pair<double, pair<int, int>> newRatio = {delta, {passed, total}};
            pop_heap(ratios.begin(), ratios.end());
            ratios.pop_back();
            ratios.push_back(newRatio);
            push_heap(ratios.begin(), ratios.end(), less<pair<double, pair<int, int>>>());
        }

        maxRatio /= classes.size();


        return maxRatio;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> classes = {{1,2},{3,5}};
    int extraStudents = 2;
    cout << solution.maxAverageRatio(classes, extraStudents) << endl;
    return 0;
}
