class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return n ^ ((1 << n.bit_length()) - 1)


if __name__ == "__main__":
    sol = Solution()
    print(sol.bitwiseComplement(0))
