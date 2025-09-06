#include <iostream>

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 <= num2) return -1;
        int i;


        for (i = 1; (1 <<( i - 1)) <= (long long)num1 -
            (num2 >= 0? 0:(long long)num2 * i);
             i++) {
            unsigned long long check = (long long)num1 - (long long)num2 * i;
            if (checkMax1(check, i))
                return i;
        }
        return -1;
    }
private:
    bool checkMax1(unsigned long long check, int max) {
        int count = 0;
        while (check != 0) {
            if ((check & 0x1) == 0x1) count++;
            check >>= 1;
        }
        if (count <= max)
            return true;
        return false;
    }
};



int main() {
    Solution solution;
    int num1 = 16;
    int num2 = 10;

    std::cout << solution.makeTheIntegerZero(num1, num2);
    return 0;
}
