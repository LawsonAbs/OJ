class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        text1 = "#"+ text1
        text2 = "#"+ text2
        m,n = len(text2), len(text1)
        dp = [[0] * len(text2) for i in range(len(text1))]
        
        for i in range(1,n):
            for j in range(1,m):
                if text1[i] == text2[j]:
                    dp[i][j] = max(dp[i-1][j-1]+1,dp[i-1][j],dp[i][j-1])
                else:
                    dp[i][j] = max(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])
        print(dp)
        return dp[n-1][m-1]

t1 = "abcde"
t2 = "ace"
s = Solution()
s.longestCommonSubsequence(t1,t2)