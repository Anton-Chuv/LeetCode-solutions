class Solution:
    def sumOfSquares(self, nums: list[int]) -> int:
        ans = 0
        l = len(nums)
        for i, v in enumerate(nums, start=1):
            if l % i == 0:
                ans += v*v
        return ans