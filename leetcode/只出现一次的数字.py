'''
想法：
使用位运算: a ^ a = 0， 0^b = b
'''
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int: 
        res = nums[0]
        for i in range(1,len(nums)):
            res =  res ^ nums[i]
        return res


s = Solution()
# nums = [1,2,3,2,1]
nums = [2,2,1]
out = s.singleNumber(nums)
print(out)