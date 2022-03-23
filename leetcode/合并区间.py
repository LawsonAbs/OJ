# 还需要注意一点是：如果有连续多个可以合并的区间，则也需要一起合并，所以单独使用out作为结果集合就不合适
from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:        
        a = sorted(intervals,key = lambda item:item[0])
        # print(a)
        if len(a) == 1: # 如果只有一项
            return a
        
        out = []
        # 遍历item
        pre_left,pre_right = a[0]        
        for i in range(1,len(a)): # 从第1项开始
            item = a[i]
            left,right = item
            if left >= pre_left and left <= pre_right: 
                pre_right = max(right,pre_right) # 更改区间的右侧，注意这里是取二者的较大值
                # out.append([pre_left,right])
                if i == len(a)-1:
                    out.append([pre_left,pre_right])
            else:
                out.append([pre_left,pre_right]) # 注意这里是放前一个
                pre_left = left
                pre_right = right
                if(i == len(a)-1): # 如果是最后一项，当前项也给放上
                    out.append([left,right])         
        return out

intervals = [[8,10],[1,3],[3,5],[15,18],[2,6]]
# intervals = [[3,5],[1,3]]
# intervals = [[3,5]]
# intervals = [[1,3],[1,6],[1,10],[1,18]]
# intervals = [[1,4],[5,6]]
s = Solution()
print(s.merge(intervals))