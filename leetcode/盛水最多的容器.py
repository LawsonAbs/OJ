from typing import List

'''
容器的面积只跟两边柱子的高度和容器的底部长有关，很容易就想到使用双指针来解决这个问题。
但有个问题是：
01.什么情况移动哪个指针？
当 height[left] < height[right]时，left ++，反之 right--
这么做的原因是：要想使面积最大，要么补柱子的高度，要么补容器的宽度。但是宽度最开始是最长的，所以我们的策略只有是缩短宽度，来尽量提升高度了。
'''
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0 #  len(height) * min(height[0],height[-1]) # 最大的面积
        
        left = 0 
        right = len(height) -1 
        while(left <= right):
            cur_area = min(height[left],height[right]) * (right-left)
            max_area = max(max_area,cur_area)
            if height[left] <= height[right]: # 应该比较的是左右两根柱子的高度
                left += 1 
            else:
                right -= 1
        return max_area
    
    # 常规的方法写这道题，O(n^2)的复杂度
    def maxArea_normal(self, height: List[int]) -> int:
        info = []
        for i in range(len(height)):
            info.append((i,height[i]))
        # 先按照x[1]排序，接着按照 x[0] 排序    
        info.sort(key=lambda x:(x[1],-x[0]),reverse=True)
        print(info)
        max_area = min(info[0][1],info[1][1]) * abs(info[0][0]-info[1][0])
        # 找出两个峰值
        left = min(info[0][0],info[1][0])
        right = max(info[0][0],info[1][0])

        for i in range(left+1):
            for j in range(right,len(height)):
                cur_aera = (j-i) * min(height[i],height[j])
                max_area = max(max_area,cur_aera)
        return max_area
s = Solution()
# nums = [1,8,6,2,5,4,8,3,7]
nums = [1,1]
out = s.maxArea(nums)
print(out)