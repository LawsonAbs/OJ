from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.bi_search_left(nums,target)
        
        # 没有找到
        if left == -1:
            return [-1,-1]
        else:
            right = self.bi_search_right(nums,target)
            return [left,right]

    # 二分查找下界
    def bi_search_left(self,nums,target):
        left ,right = 0, len(nums)-1
        
        while(left < right): # 这里是<，如果带上=，则会因为下面的 right = mid 这个死循环
            mid = (left+right) // 2
            if nums[mid] == target: # 可能是目标索引
               right = mid 
            elif nums[mid] < target:
                left = mid+1
            elif nums[mid] > target:
                right = mid-1
        
        # 退出循环的时候 left = right 
        if nums[left] == target:
            return left
        else:
            return -1

    # 二分查找上界
    def bi_search_right(self,nums,target):
        left ,right = 0 ,len(nums)-1
        while(left <= right):
            mid = (left+right) // 2
            if nums[mid] <= target:
                left = mid+1  # 如果 nums[mid]=target，且是最右端值
            elif nums[mid] > target:
                right = mid-1
        
        # 因为可能会越过正确答案
        if nums[right] == target:
            return right
        return -1

s = Solution()
left_res = s.bi_search_left(nums = [1,8], target = 8)
print(left_res)

right_res = s.bi_search_right(nums = [1,8], target = 8)
print(right_res)