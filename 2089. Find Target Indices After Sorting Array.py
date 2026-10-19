class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        eqCount = 0
        lowCount = 0
        for i in nums:
            if i == target:
                eqCount += 1
            if i < target:
                lowCount += 1
        return list(range(lowCount, lowCount+eqCount))