#include <cstdlib>
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distX = abs(x - z);
        int distY = abs(y - z);
        if (distX < distY) return 1;
        if (distX > distY) return 2;
        return 0;
    }
};
