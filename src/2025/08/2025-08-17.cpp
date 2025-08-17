#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double sum = 0;
        if (k == 0)
            return 1.0;
        vector<double> p(maxPts, 0);
        for (int i = 1; i < k; i++) {
            double q = 0; // prob of get exact i score on any taken card within i card taken
            if (i <= maxPts) // take score with one card
                q = 1.0 / maxPts;
            q += sum / maxPts;

            p.push_back(q);
            sum += q - p[0];
            p.erase(p.begin());
        }
        double ans = 0;
        for (int i = k; i <= n; i++) {
            double q = 0; // prob of get exact i score on any taken card within i card taken
            if (i <= maxPts) // take score with one card
                q = 1.0 / maxPts;
            q += sum / maxPts;
            if (p.size() > 0) {
                sum -= p[0];
                p.erase(p.begin());
            }
            ans += q;
        }

        return ans;
    }
};