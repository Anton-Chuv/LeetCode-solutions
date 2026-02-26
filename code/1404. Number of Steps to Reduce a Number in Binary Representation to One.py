class Solution:
    def numSteps(self, s: str) -> int:
        steps = 0
        r = 0
        for i in range(len(s) - 1, 0, -1):
            if r:
                if s[i] == "1":
                    s = s[:i] + "0" + s[i + 1 :]
                else:
                    s = s[:i] + "1" + s[i + 1 :]
                    r = 0
            if s[i] == "1":
                steps += 2
                r = 1
            else:
                steps += 1
        return steps + r


if __name__ == "__main__":
    solution = Solution()
    print(solution.numSteps("1101"))
