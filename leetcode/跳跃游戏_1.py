from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        dp = [0 ] * len(nums) #dp[i]表示位置i能往后走的最大距离，如果是0，则表示该位置无法前进        
        dp[0] = nums[0]
        if len(nums) == 1:
            return True
        for i in range(1,len(nums)):
            if dp[i-1] == 0:
                return False
            dp[i] = max(dp[i-1]-1,nums[i])            
        # 如果能顺利到达最后，直接就是可以到达
        return True    
s = Solution()
nums = [2,0,0]
print(s.canJump(nums))