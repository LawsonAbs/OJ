from typing import List
from copy import copy

'''
想法一：
01.改变正负号。如果是偶数个，则符号全部变正。
02.根据改变后的符号再来求最大积。
这种方法是有问题的：
[-1,-4,-3] 在遇到这种样例的时候，数组会变成 [1,4,-3] 这样，而不是[-1,4,3] ，然而后者才是正确的答案。
'''
# class Solution:
#     def maxProduct(self, nums: List[int]) -> int:    
#         pre_idx = None
#         cnt = 0
#         for i in range(len(nums)):
#             if nums[i] < 0 : # 如果当前的值小于0
#                 if pre_idx is None:
#                     pre_idx = i
#                 cnt += 1
#             elif nums[i] == 0: # 重置
#                 cnt = 0
#                 pre_idx = None
#             if cnt % 2 == 0 and cnt: # 已经有连续两个负号
#                 nums[pre_idx] *= -1
#                 nums[i] *=  -1 # 改符号
#                 pre_idx = None
#                 cnt = 0
        
#         # product = copy(nums)
#         print(nums)
#         max_val = 0
#         whole = 0
#         for i in range(1,len(nums)):
#             if nums[i] > 0 and nums[i-1] > 0:
#                 nums[i] = nums[i-1] * nums[i]
#                 whole += 1
#             max_val = max(max_val,nums[i])
#         if whole == len(nums): # 如果是全部数字都算进去了
#             pass
#         print(nums)
#         print(max_val)

class Solution():
    def maxProduct(self, nums: List[int]) -> int:    
        dp_min = copy(nums) # 第i项的最小值
        dp_max = copy(nums) # 第i项的最大值
        total = nums[0]
        for i in range(1,len(nums)):
            total *= nums[i]
            dp_min[i] = min(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i],nums[i])
            dp_max[i] = max(dp_min[i-1]*nums[i],dp_max[i-1]*nums[i],nums[i])
        # print(dp_max)
        res =  max(dp_max)
        return res
    

s = Solution()
nums = [-2,3,-2,4,-1,0,0,-4]
# nums = [-2,-1,-3,-4] # 得到的结果应该是12
# nums = [-1,-4,-3]
nums = [-2,-3,1] # 会计算整个数组的乘积
# nums = [-6,-2,-3,4,-5]
# nums = [-6,-2,-3,4]
# nums = [   -2,-3,4,-5]

out = s.maxProduct(nums)
print(out)