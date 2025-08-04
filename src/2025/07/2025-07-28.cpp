#include <iostream>

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums, int start = 0) {
        if (nums.size() == 1)
            return 1;
        
        int max = 0;
        int count = 1;
        for (int x: nums)
            max |= x;
        for (int i = start; i < nums.size(); i++) {
            int submax = 0;
            vector<int> subnums;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    submax |= nums[j];
                    subnums.push_back(nums[j]);
                }
            }
            if (submax == max) {
                count += countMaxOrSubsets(subnums, i);
                for (int i: subnums)
                    std::cout << i << ' ';
                cout << endl;

            }
        }
        return count;
    }


};

int main() {
    // cout << "hi";
    Solution sol;
    vector<int> nums = {3,2,1,5};
    cout << sol.countMaxOrSubsets(nums);
    return 0;
}