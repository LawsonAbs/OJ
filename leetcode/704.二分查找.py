from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left ,right = 0,len(nums)-1
        while (left <= right):
            mid = (left+right)//2
            if nums[mid] > target:
                right = mid-1
            elif nums[mid] < target:
                left = mid+1
            else:
                return mid
        # 到最后肯定是找不到了，所以就必须返回-1
        return -1
        # print(nums[right])

nums = [-1,0,3,5,9,12]        
target = -1
s = Solution()
out = s.search(nums,target)
print(out)
