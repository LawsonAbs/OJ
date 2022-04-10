class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1 = len(text1)
        len2 = len(text2)

        dp = [ [0 for j in range(len2) ]for i in range(len1)]
        # print(dp)        
        for i in range(0,len1):
            for j in range(0,len2):
                if text2[j] == text1[i]:
                    if j > 0 and i > 0:
                        dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1)
                    else: # 这里的i和j值就是可能有一个为0，当有一个为0的时候，又有一个相等，所以其最大值就是1
                        dp[i][j] = 1
                else:
                    if i == 0 and j ==0 : 
                        dp[i][j] = 0
                    elif i == 0 and j > 0:
                        dp[i][j] = max(dp[i][j],dp[i][j-1])
                    elif i >0 and j == 0:
                        dp[i][j] = max(dp[i][j],dp[i-1][j])
                    elif i > 0 and j > 0:                        
                        dp[i][j] = max(dp[i][j],dp[i-1][j],dp[i][j-1])
        print(dp)
        return dp[len1-1][len2-1]

s = Solution()
text1 = "abcde"
text2 = "ace"
# text1 = "lawson"
# text2 = "lawson"

# text1 = "psnw"
# text2 = "vozsh"
# text1 = "abcba"
# text2 = "abcbcba"
# text1 = "aa"
# text2 = "aaaaaa"
text1 = "bl"
text2="yby"
out = s.longestCommonSubsequence(text1,text2)
print(out)

        