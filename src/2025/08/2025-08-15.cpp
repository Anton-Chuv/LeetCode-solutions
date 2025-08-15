class Solution {
public:
    bool isPowerOfFour(int n) {
        int power4[16] = {1,
            4,
            16,
            64,
            256,
            1024,
            4096,
            16384,
            65536,
            262144,
            1048576,
            4194304,
            16777216,
            67108864,
            268435456,
            1073741824
        };
        for (int i = 0; i < 16; i++) {
            if (n < power4[i]) return false;
            if (n == power4[i]) return true;
        }
        return false;
    }
};
