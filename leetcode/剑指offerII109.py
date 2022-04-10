from typing import List
from queue import Queue
import copy

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        cur_lock = ['0','0','0','0'] # str是不可变序列        
        return self.bfs(cur_lock,0,target,deadends)

    def bfs(self,cur_lock,dis,target,deadends): # 每次都可以改变4个位置中的任意一个
        a = ['1','2','3','4','5','6','7','8','9','0'] # a[i] = i+1
        b = ['9','0','1','2','3','4','5','6','7','8'] # a[i] = i+1
        que = Queue()

        if ''.join(cur_lock) not in deadends:
            que.put((cur_lock,0))
            vis = set()
            vis.add(''.join(cur_lock))
        else:
            return -1
        while(que.qsize()>0):
            cur_lock,dis = que.get() # 获取队首
            # print(''.join(cur_lock))

            if ''.join(cur_lock) == target:                
                return dis
            
            # 每次改动一位
            for i in range(4):
                tmp = copy.copy(cur_lock)
                # 每次都有一个选择
                tmp[i] = a[int(tmp[i])] # 加一
                str_1 = ''.join(tmp)
                if str_1 not in deadends and str_1 not in vis:
                        vis.add(str_1)
                        # print(''.join(cur_lock))
                        que.put((tmp,dis+1))
                
                # TODO:因为这里上面的值已经被修改了
                tmp = copy.copy(cur_lock)
                tmp[i] = b[int(tmp[i])] # 减一
                str_2 = ''.join(tmp)
                if str_2 not in deadends and str_2 not in vis:
                        vis.add(str_2)
                        que.put((tmp,dis+1))    
        return -1

s = Solution()
# deadends = ["0201","0101","0102","1212","2002"]
# target = "0202"
# deadends = ['8888']
# target = '0009'
# deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"]
# target = "8888"
deadends = ['0000']
target = '8888'
out = s.openLock(deadends,target)
print(out)