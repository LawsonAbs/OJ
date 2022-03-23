from typing import List
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.bi_search_left(nums,target)
        # print(left)
        if left == -1:
            return [-1,-1]
        else:
            right = self.bi_search_right(nums,target)
            # print(left,right-1)
            return [left,right-1]

    # 定义一个二分查找的方法，如果与该值相等，则返回该值第一次出现的位置；如果该值未出现，则返回-1
    def bi_search_left(self,nums,target):
        low = 0
        high = len(nums) -1  
        while(low < high):            
            mid = (low+high) // 2 
            if(nums[mid] > target):
                high = mid - 1
            elif nums[mid] < target:
                low = mid + 1
            elif nums[mid] == target: # 如果值相等
                high = mid # 不能减一，因为可能就是目标位置
        if nums[low] != target: # 说明没有找到，直接返回-1
            return -1
        return low # 返回需要的下标


    # 定义一个二分查找的方法，如果与该值相等，则返回该值最后一次出现的位置；如果该值未出现，则
    def bi_search_right(self,nums,target):
        low = 0
        high = len(nums) -1  
        while(low <= high):
            mid = (low+high) // 2 
            if(nums[mid] > target):
                high = mid - 1
            elif nums[mid] <= target:
                low = mid + 1
            
        # if nums[low] != target: # 说明没有找到，直接返回-1
        #     return -1
        return low # 返回需要的下标


s = Solution()
nums = []
target = 0
print(s.searchRange(nums,target))
