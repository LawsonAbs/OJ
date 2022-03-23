from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums) # dp[i] 表示第i位置的最大值
        res = 1
        dp[0] = 1
        for i in range(len(nums)):
            for j in range(0,i): 
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i],dp[j]+1)
                    res = max(res,dp[i])
        print(dp)
        return res

s = Solution()
nums = [10,9,2,5,3,7,101,18]
print(s.lengthOfLIS(nums))