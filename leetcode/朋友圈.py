from typing import List

class Solution:
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        record = [0] * len(isConnected) # 得到每个城市是否遍历过
        res = 0  # 省份的个数
        for i in range(len(isConnected)):
            if record[i] == 0:
                self.dfs(i,isConnected,record)
                res +=1 
        return res

    # 当前正在访问的城市下标
    def dfs(self,cur,isConnected,record):
        for i in range(len(isConnected)):
            if isConnected[cur][i] == 1 and  record[i] == 0: # 联通且未访问
                record[i] = 1 
                self.dfs(i,isConnected,record)

s = Solution()
# isConnected = [[1,0,0],[0,1,0],[0,0,1]]
isConnected = [[1,1,0],[1,1,1],[0,1,1]]
res = s.findCircleNum(isConnected)
print(res)