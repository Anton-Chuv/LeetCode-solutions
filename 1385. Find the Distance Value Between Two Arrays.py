class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0
        for i in arr1:
            for j in arr2:
                if abs(i-j) <= d:
                    ans += 1
                    break
        return len(arr1) - ans