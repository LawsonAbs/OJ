from typing import List
import numpy as np
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [0 for i in range(len(nums))] #dp[i]表示是否能达到i位置。1表示可，0表示不可
        
        dp[0] = 1 # 1 本身就可以
        
        for i in range(1,len(nums)):
            if dp[i-1]: # 
                dp[i:i+nums[i-1]] = [1] * (nums[i-1]) # 不能将一个
        print(dp)
        if dp[-1] :
            return True
        return False

s = Solution()
nums = [2,3,1,1,4]
s.canJump(nums)