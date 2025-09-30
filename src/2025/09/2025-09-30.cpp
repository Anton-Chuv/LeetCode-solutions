#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            result += (nums[i] * binomMod10(i, n-1));
        }
        return result % 10;
    }
private:
    int binom(int k, int n) {
        if (k > n) return 0;
        return factorial(n) / (factorial(k) * factorial(n-k));
    }
    int binomMod10(int k, int n) {
        int SunziTable[2][5] = {
            {0, 6, 2, 8, 4},
            {5, 1, 7, 3, 9}
        };
        return SunziTable[binomMod2(k, n)][binomMod5(k, n)];
    }
    int binomMod2(int k, int n) {
        return (k & n) == k;
    }
    int binomMod5(int k, int n) {
        int res = binom(k%5, n%5);
        while (n > 0) {
            n /= 5;
            k /= 5;
            res = (res * binom(k%5, n%5));
        }
        return res%5;
    }
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++)
            result *= i;
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,6,6,2,5,7};
    cout << solution.triangularSum(nums) << endl;
    return 0;
}
