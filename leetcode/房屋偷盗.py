from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        dp[0] = nums[0]
        if len(nums) >1:
            dp[1] = max(nums[0],nums[1])
            for i in range(2,len(nums)):
                money = nums[i]
                dp[i] = max(dp[i-1],dp[i-2]+money)        
            # print(dp) 
        return max(dp)

s = Solution()
nums = [7,2,9,13,1]
# nums = [7]
out = s.rob(nums)
print(out)
