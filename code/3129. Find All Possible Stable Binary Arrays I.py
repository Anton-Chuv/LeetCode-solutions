class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 10**9 + 7

        # dp[i][j][k] where:
        # i = number of 0s used
        # j = number of 1s used
        # k = last element (0 or 1)
        # l = consecutive count of last element
        dp = [
            [[[0] * (limit + 1) for _ in range(2)] for __ in range(one + 1)]
            for ___ in range(zero + 1)
        ]

        # Base cases
        if zero > 0:
            dp[1][0][0][1] = 1  # [0]
        if one > 0:
            dp[0][1][1][1] = 1  # [1]

        for i in range(zero + 1):
            for j in range(one + 1):
                for k in range(2):
                    for l in range(1, limit + 1):
                        if dp[i][j][k][l] == 0:
                            continue

                        # Try to add opposite element
                        if k == 0 and j < one:
                            new_count = dp[i][j][k][l] + dp[i][j + 1][1][1]
                            if new_count >= MOD:
                                new_count -= MOD
                            dp[i][j + 1][1][1] = new_count
                        elif k == 1 and i < zero:
                            new_count = dp[i][j][k][l] + dp[i + 1][j][0][1]
                            if new_count >= MOD:
                                new_count -= MOD
                            dp[i + 1][j][0][1] = new_count

                        # Try to extend current element
                        if l < limit:
                            if k == 0 and i < zero:
                                new_count = dp[i][j][k][l] + dp[i + 1][j][0][l + 1]
                                if new_count >= MOD:
                                    new_count -= MOD
                                dp[i + 1][j][0][l + 1] = new_count
                            elif k == 1 and j < one:
                                new_count = dp[i][j][k][l] + dp[i][j + 1][1][l + 1]
                                if new_count >= MOD:
                                    new_count -= MOD
                                dp[i][j + 1][1][l + 1] = new_count

        # Sum all valid arrays
        result = 0
        for k in range(2):
            for l in range(1, limit + 1):
                result = (result + dp[zero][one][k][l]) % MOD

        return result


# Testing some LLM
# This work, but
## Time Limit Exceeded
## 668 / 670 testcases passed
