class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        max = nums[0]
        for i in range(len(nums)):
            if (max - min(nums[i:])) <= k:
                return i
            if nums[i] > max:
                max = nums[i]
        return -1
