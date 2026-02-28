class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 10**9 + 7
        result = 0

        for i in range(1, n + 1):
            # Convert number to binary string and remove '0b' prefix
            binary_str = bin(i)[2:]
            # For each bit in the binary string, update the result
            for bit in binary_str:
                result = (result << 1) | int(bit)
                result %= MOD

        return result
