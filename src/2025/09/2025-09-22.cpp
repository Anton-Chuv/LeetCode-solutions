class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = 0;
        for (auto& pair : freq) {
            maxFreq = max(maxFreq, pair.second);
        }
        int res = count_if(freq.begin(), freq.end(), [maxFreq](const auto& pair) {
            return pair.second == maxFreq;
        });

        return res * maxFreq;
    }
};
