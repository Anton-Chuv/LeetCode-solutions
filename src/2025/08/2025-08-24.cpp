#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        int countPrev = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                count++;
                countPrev++;
            }
            else{
                maxCount = max(maxCount, count);
                // maxCount = maxCount >= count ? maxCount : count;
                if (i + 1 < nums.size() && nums[i + 1]) {
                    count = countPrev;
                    countPrev = 0;
                }
                else {
                    count = 0;
                    countPrev = 0;
                }
            }

        }
        maxCount = max(maxCount, count);
        if (maxCount == nums.size()) // if there is no "0" to remove
            maxCount--;
        return maxCount;
    }
};


int main() {
    Solution solution;

    vector<int> nums = {1, 1, 0, 1};
    cout << solution.longestSubarray(nums);

    return 0;
}
