class Solution:
    def sumNums(self, n: int) -> int:
        if n == 1 or n == 0:
            return n
        return self.sumNums(n-1)+n
s = Solution()
out = s.sumNums(9)
print(out)