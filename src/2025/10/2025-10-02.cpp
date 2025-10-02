#include <cmath>
class Solution {
public:
    int maxBottlesDrunk(int n, int k) {
        int res = n;
        res += (3 - 2 * k + sqrt(4*k*k - 12 * k + 8 * n + 1) ) / 2;
        return res;
    }
};
