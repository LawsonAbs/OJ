from typing import List
from copy import copy 

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:  
        res = []
        self.dfs(0,res,len(graph),[0],graph)
        return res

    def dfs(self,cur,res,n,path,graph):
        if cur == n-1:
            res.append(copy(path))
            return 
        for i in range(len(graph[cur])):
            path.append(graph[cur][i])
            self.dfs(graph[cur][i],res,n,path,graph)
            path.pop()
        
s = Solution()
# graph = [[4,3,1],[3,2,4],[3],[4],[]]
graph = [[1,2,3],[2],[3],[]]
out = s.allPathsSourceTarget(graph)
print(out)