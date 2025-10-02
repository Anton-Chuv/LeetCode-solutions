#include <cmath>
class Solution {
public:
    int maxBottlesDrunk(int n, int k) {
        int res = n;
        res += 1.0 * (3 - 2 * k)/2 + std::sqrt( 1.0 * (2*k-3)/2*(2*k-3)/2 - 1.0 * 4 / 2 * (2 - 2 * n)/2);
        return res;
    }
};
