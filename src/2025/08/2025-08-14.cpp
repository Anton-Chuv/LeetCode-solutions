#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char prev[2] = "a";
        string max = "";
        for (char x: num) {
            if (x == prev[0] && x == prev[1] && x > max[0]) {
                max = "";
                for (int i = 0; i < 3; i++) max += x;
            }
            prev[1] = prev[0];
            prev[0] = x;
        }
        return max;
    }
};
