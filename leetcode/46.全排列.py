from typing import List
from copy import copy

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        vis = [0] * len(nums)
        path = []
        res = []
        for i in range(len(nums)):
            path.append(nums[i])
            vis[i] = 1
            self.dfs(path,len(nums),res,vis,nums)
            vis[i] = 0
            path.pop()
        print(res)

    # path
    # n 总个数
    def dfs(self,path,n,res,vis,nums):
        if len(path) == n: # 返回所有值
            res.append(copy(path))
            return 
        for i in range(n):
            if vis[i] == 0:
                vis[i] = 1
                path.append(nums[i])
                self.dfs(path,n,res,vis,nums)
                path.pop()
                vis[i] = 0
                

s = Solution()
nums = [1,2,3]
s.permute(nums)