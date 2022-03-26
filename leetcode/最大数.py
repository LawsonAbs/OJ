from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # 对nums中的进行两两比较，找出一个最优的排序
        # 将最大的放在最前面
        # 类似冒泡排序
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                num1 = int(str(nums[i]) + str(nums[j]))
                num2 = int(str(nums[j]) + str(nums[i]))
                if num1 < num2: # 交换
                    nums[i] ,nums[j] = nums[j],nums[i]
    
        res = ""
        for i in nums:
            res +=str(i)
        res =  res.lstrip("0")
        if len(res) >= 1:
            return res
        else:
            return "0"
        

nums = [3,30,34,5,9]
nums = [2]
# nums = [0,0,1] # 如果是全0
s = Solution()
res = s.largestNumber(nums)
print(res)