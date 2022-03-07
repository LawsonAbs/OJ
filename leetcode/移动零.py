from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        j = len(nums) - 1
        while(i>=0): # 循环终止的条件
            if nums[i] == 0 :
                temp = nums[i]
                for k in range(i,j):
                    nums[k] = nums[k+1]
                nums[j] = temp # 将0 还原
                j = j-1 # 因为只移动了一个0，所以往前进一位即可
            i = i-1
        