from typing import List
'''
使用一个临时数组来对原数组进行修改，保证不改变原变量的地址
'''
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        print(id(nums))
        # nums[-1] = 100
        k %= len(nums) # 可能 k 的值超过了数组的长度，所以需要注意一下。
        res = nums[-k:]+nums[0:-k]
        for i in range(len(nums)):
            nums[i] = res[i]
        # nums = tail + head # 这个操作重新对nums赋值了，所以不是正解
        # print(tail, head)
        print(id(nums))
        print(nums)

    
solution = Solution()
nums=[1,2,3,4,5,6,7]
k=10
solution.rotate(nums,k)

