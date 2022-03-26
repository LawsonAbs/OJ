from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            # 循环的条件是：
            # 1.大于0
            # 2.不满足条件 nums[i]  = i+1
            # 3.nums[i] 的下标在合理的范围内
            # 4.交换的两个数不能相同
            while(nums[i] > 0 and i+1 != nums[i] and nums[i]-1 < len(nums) and nums[i]!=nums[nums[i]-1]):
                # 待交换的两个数是 nums[nums[i]-1] 和 nums[i]
                # nums[i] 应该待在下标 nums[i]-1处
                # 每交换一次，就会让一个数回到正确的位置下
                nums[nums[i]-1],nums[i] = nums[i] ,nums[nums[i]-1]

        for i in range(len(nums)):
            if i+1 != nums[i]:
                return i+1
        if i == len(nums)-1:
            return i+2

s = Solution()
nums = [3,1,3] #
out = s.firstMissingPositive(nums)
print(out)