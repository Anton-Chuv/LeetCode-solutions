class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        i = 0
        l = len(s)
        while i < l:
            if s[i] == "1":
                break
            i += 1
        else:
            return False
        while i < l:
            if s[i] == "0":
                break
            i += 1
        while i < l:
            if s[i] == "1":
                return False
            i += 1
        return True


if __name__ == "__main__":
    s = Solution()
    print(s.checkOnesSegment("0000"))
