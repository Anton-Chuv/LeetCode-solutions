class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                len++;
            } else {
                if (len > 0)
                    count += 1.0 * len * (len + 1) / 2;
                len = 0;
            }
        }
        if (len > 0)
            count += 1.0 * len * (len + 1) / 2;

        return count;
    }
};
