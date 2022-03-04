from typing import List
'''
有没有O(1)的空间算法？
步骤如下：
01.全部反转
02.反转前k个，再反转剩余的len(nums)-k个

'''
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # print(id(nums))
        k = k%len(nums)
        nums.reverse() # 只能对整个list进行翻转
        self.reverse_head(nums,k)
        self.reverse_tail(nums,k)
        
        # 无法对一个list的局部进行逆转        
        # print(id(nums))
        # print(nums)
    
    # 对局部的list进行逆转
    # 这里传入的参数nums，会修改原数组！    
    def reverse_head(self,nums,k):
        i = 0
        j = k-1
        while(i < j):
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            i += 1
            j -= 1
        # print(nums)

    def reverse_tail(self,nums,k):
        i = k
        j = len(nums)-1
        while(i < j):
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
            i += 1
            j -= 1
        # print(nums)

solution = Solution()
nums=[1,2,3,4,5,6,7]
k=3
solution.rotate(nums,k)

