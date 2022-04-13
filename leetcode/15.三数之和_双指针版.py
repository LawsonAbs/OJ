from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        pre = None
        # 每次定下一个数
        for i in range(len(nums)):            
            # 判断是否是连续的两个数是否相同
            if pre is not None and nums[i] == pre:                
                continue
            pre = nums[i]
            left = i + 1
            right = len(nums)- 1 
            # left 与 right 为寻找的区间

            while(left < right):
                if -nums[i] == nums[left] + nums[right]: # 判断二者的加和
                    res.append([nums[i],nums[left],nums[right]])
                    # 找到一个不相等的数
                    cur_left = nums[left]
                    cur_right = nums[right]
                    while(left < len(nums) and nums[left]==cur_left  ):
                        left += 1
                    while(right >= 0 and nums[right] == cur_right  ):
                        right -=1
                elif -nums[i] > nums[left] + nums[right] :
                    left+=1
                elif -nums[i] < nums[left] + nums[right]:
                    right -=1 
        return res

# nums = [-2,-1,-1,0,1,1,2]
nums = [-2,0,1,1,2]
# nums = [-1,0,1,2,-1,-4]
nums = [0]
# nums = [-2,0,0,2,2]
nums= [0,0,0]
s = Solution()
out = s.threeSum(nums)
print(out)


