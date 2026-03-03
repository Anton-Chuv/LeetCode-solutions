class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 0 and k == -1:
            return "0"
        if n > 0 and k == -1:
            s = self.findKthBit(n - 1, -1)
            sr = (
                self.findKthBit(n - 1, -1)
                .replace("1", "*")
                .replace("0", "1")
                .replace("*", "0")
            )[::-1]
            return s + "1" + sr

        s = self.findKthBit(n - 1, -1)
        return s[k - 1]


if __name__ == "__main__":
    solution = Solution()
    n = 4
    k = 11
    print(solution.findKthBit(n, k))
