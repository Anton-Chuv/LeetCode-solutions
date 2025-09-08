class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (checkNM(n, n-1)) return {n, n-1};
        }
        return {-1};
    }
private:
    bool checkNM(int n, int m) {
        bool o = true;
        for (int i = 1; i < n; i *= 10)
            if (n/i%10 == 0) return false;
        for (int i = 1; i < m; i *= 10)
            if (m/i%10 == 0) return false;
        return true;
    }
};
