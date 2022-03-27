from typing import List
from collections import defaultdict

from sympy import re
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        conditions = defaultdict(list)
        inDegree = [0] * (numCourses)
        record = [0] * (numCourses)

        # 预处理
        for item in prerequisites:
            a,b = item # 上a之前先上b
            inDegree[a] += 1 # 有限制
            conditions[b].append(a) # a受b影响

        self.dfs(numCourses,inDegree,record,conditions)

        for i in range(numCourses):
            if record[i] == 0:
                return False
        return True

    
    def dfs(self,numCourses,inDegree,record,conditions):
        for i in range(numCourses):
            if record[i] == 0 and inDegree[i] == 0: # 尚未访问 且 没有限制了
                for j in conditions[i]: # 去掉限制
                    inDegree[j] -= 1
                record[i] = 1
                self.dfs(numCourses,inDegree,record,conditions)

# numCourses = 2
# prerequisites = [[1,0]]
numCourses = 4
# prerequisites = [[1,0],[2,1],[3,2],[1,3]]
prerequisites = [[1,0],[2,1],[3,2],[2,3]]
prerequisites = [[1,0],[2,1],[3,2],[0,3]]
s = Solution()
res = s.canFinish(numCourses,prerequisites)
print(res)
