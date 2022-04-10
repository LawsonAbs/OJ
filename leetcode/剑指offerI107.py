from typing import List
from queue import Queue

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat) # 行数
        n = len(mat[0]) # 列数
        out = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):                
                out[i][j] = self.bfs(i,j,0,m,n,mat)

        return out

    # 采用bfs，找出该坐标到最邻近的0 的距离
    # m是行坐标个数
    # n是纵坐标个数
    def bfs(self,x,y,dis,m,n,mat):
        que = Queue(maxsize=0)
        vis = set() # 访问过的下标
        que.put((x,y,0))
        # 放入位置和距离
        while(que.qsize!=0):
            x,y,dis = que.get() # 获取队首
            if mat[x][y] == 0:
                return dis
            for i in range(-1,2):
                for j in range(-1,2):
                    if abs(i) == abs(j): # 去除远角
                        continue
                    new_x,new_y = x+i,y+j # 更新坐标信息
                    if new_x >= 0 and new_y >= 0 and new_x < m  and  new_y < n:
                        if (new_x,new_y) not in vis:
                            que.put((new_x,new_y,dis+1))
                            vis.add((new_x,new_y))
    
s = Solution()
# mat = [[0,0,0],[0,1,0],[1,1,1]]
mat = [[0,0,0,1],[0,1,0,1]]
mat = [[0,0,0,1]]
mat = [[0,0,0,0]]
mat = [[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[0,0,0]]
res = s.updateMatrix(mat)
print(res)

