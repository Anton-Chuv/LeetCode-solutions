class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        oddMin = 10**10
        evenMin = 10**10
        for num in nums1:
            if num % 2 == 1:
                if num < oddMin:
                    oddMin = num
            else:
                if num < evenMin:
                    evenMin = num
        if oddMin < evenMin or oddMin == 10**10:
            return True
        return False