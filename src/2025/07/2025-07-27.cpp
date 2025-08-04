#include <iostream>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int direction = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                if (direction == -1) count++;
                direction = 1;
            }
            if (nums[i] < nums[i - 1]) {
                if (direction == 1) count++;
                direction = -1;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    // cout << "Hello world!";
    Solution sol;
    vector<int> nums = {6,6,5,5,4,1};
    cout << sol.countHillValley(nums);

    return 0;
}
