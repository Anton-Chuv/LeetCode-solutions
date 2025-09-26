class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        int count = 0;
        int n = nums.size();

        // Iterate over the array from the end
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            // Find the number of valid triangles using two pointers
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }
};
