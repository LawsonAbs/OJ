from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:        
        answers = [1] * len(nums) # 存储结果         
        # 再计算右侧的乘积
        for i in reversed(range(0,len(nums)-1)):
            answers[i] = answers[i+1] * nums[i+1] 
        # print(answers)
        
        # 先计算左侧的乘积
        left = 1
        for i in range(1,len(nums)):
            left *= nums[i-1]            
            answers[i] =  left * answers[i]
        # print(answers)
        
        return max(answers)
            
s = Solution()
# nums = [3,2,3,4]
nums = [0,2,1,4]
out = s.productExceptSelf(nums)
print(out)
