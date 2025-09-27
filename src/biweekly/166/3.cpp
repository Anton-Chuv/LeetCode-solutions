#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int distinctPoints(string s, int k) {
        set<pair<int, int>> sumK;
        pair<int, int> window = {0, 0};
        for (int i = 0; i < k; i++) {
            if (s[i] == 'U') window.second++;
            if (s[i] == 'D') window.second--;
            if (s[i] == 'R') window.first++;
            if (s[i] == 'L') window.first--;
        }
        sumK.insert(window);
        for (int i = k; i < s.length(); i++) {
            if (s[i-k] == 'U') window.second--;
            if (s[i-k] == 'D') window.second++;
            if (s[i-k] == 'R') window.first--;
            if (s[i-k] == 'L') window.first++;
            if (s[i] == 'U') window.second++;
            if (s[i] == 'D') window.second--;
            if (s[i] == 'R') window.first++;
            if (s[i] == 'L') window.first--;
            sumK.insert(window);
        }
        return sumK.size();
    }
};
