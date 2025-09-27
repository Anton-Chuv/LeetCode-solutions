
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> freq(26,0);
        for (char c: s) {
            freq[c-'a']++;
        }
        map<int, string> groups;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                groups[freq[i]] = "" + groups[freq[i]] + char('a' + i);
        }
        string maxGroup = "";
        int maxFreq = 0;
        for (auto const& x : groups) {
            if (x.second.length() > maxGroup.length()) {
                maxGroup = x.second;
                maxFreq = x.first;
            }
            if (x.second.length() == maxGroup.length() && x.first > maxFreq) {
                maxGroup = x.second;
                maxFreq = x.first;
            }
        }
        return maxGroup;
    }
};

int main() {
    Solution sol;
    cout << sol.majorityFrequencyGroup("aaabbbccdddde");
    return 0;
}
