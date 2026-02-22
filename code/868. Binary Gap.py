class Solution:
    def binaryGap(self, n: int) -> int:
        maxLen = 0
        left_index = 0
        for i, b in enumerate("{0:b}".format(n)):
            if b == "1":
                len = i - left_index
                if len > maxLen:
                    maxLen = len
                left_index = i

        return maxLen
