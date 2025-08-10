#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        long int power2 = 1;
        while (str.length() > to_string(power2).length())
            power2 *= 2;
        while (str.length() >= to_string(power2).length()) {
            string str2 = to_string(power2);
            sort(str2.begin(),str2.end());
            if (str == str2)
                return true;
            power2 *= 2;
        }


        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.reorderedPowerOf2(46);

    return 0;
}
