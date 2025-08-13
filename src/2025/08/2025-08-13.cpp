class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        while (n % 3 == 0) {
            n /= 3;
            if (n == 1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    return solution.isPowerOfThree(45);
}
