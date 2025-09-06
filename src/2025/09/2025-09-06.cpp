#include <iostream>

using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long count = 0;
        for (vector<int> range: queries)
            count += operRange(range);
        return count;
    }
private:
    long long operRange(vector<int> range) {
        long long bottom = range[0];
        long long upper = range[1];
        long long count = 0;
        long long i = 0;
        if (upper < 4)
            return (upper - bottom+ 1) / 2 + ((upper - bottom + 1) % 2 ? 1 :0);
        while ((1 << (i*2)) < bottom) i++;
        if ((1 << (i*2)) > upper)
            return (upper - bottom+ 1) * i / 2 + (((upper - bottom+ 1) * i) % 2 ? 1 :0);
        long long r = (1 << (i*2)) - bottom;
        count += r * i;
        i++;
        for (; (1 << (i*2)) <= upper; i++) {
            count += ((1 << (i*2)) - (1 << (i*2-2))) * i;
        }
        count += (upper - (1 << (i*2-2))+1) * i;
        return count / 2 + (count % 2 ? 1 :0);
    }
};

int main() {
    Solution solution;

    vector< vector<int> > q = {{2,4},{1,2}};


    cout << solution.minOperations(q);
}
