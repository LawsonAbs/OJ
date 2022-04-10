from queue import Queue
import queue 

class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        que = Queue(maxsize= 0)
        # vis 表示是否访问过
        vis = set()
        cnt = 0
        # 初始点为(0,0)
        que.put((0,0)) # 放入一个坐标信息
        while(que.qsize() > 0):
            x,y = que.get() # 获取队首（坐标）信息
            if x < m and x >= 0 and y >= 0 and y<n:
                if self.cal(x,y,k) and (x,y) not in vis:
                    vis.add((x,y))
                    cnt += 1
                    # 分别向各个方向扩展            
                    que.put((x+1,y))
                    que.put((x-1,y))
                    que.put((x,y+1))
                    que.put((x,y-1))
        return cnt
    def cal(self,x,y,k): # 计算(x,y)坐标点数位之和
        tot = 0
        while(x):
            x,b = divmod(x,10)
            tot += b
        while(y):
            y,b = divmod(y,10)
            tot += b
        return tot <= k


s = Solution()
# m = 2
# n = 3
# k = 1
m,n,k = 3,1,0
out = s.movingCount(m,n,k)
print(out)