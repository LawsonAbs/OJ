from typing import List
# from collections import deque # 引入双端队列
from queue import Queue

# 因为Queue 没有获取队首（但不删除队首的方法），所以这里使用数组实现

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        que = Queue() 
        maxV = [] # 结果数组        
        que.put(0) 
        
        for i in range(len(nums)):                        
            rear = que.queue[-1] # 队尾
            
            # 当队列非空
            while(que.qsize() and nums[i] >= nums[rear] and (i-rear)<k ):
                del que.queue[-1] # 删除队尾
                if que.qsize(): # 如果还有值，则继续删除
                    rear = que.queue[-1]

            que.put(i) # 加入当前的数
            front = que.queue[0] # 获取队首元素
            while(i-front >= k):
                que.get() # 删除
                front = que.queue[0] # 获取队首

            if i >= k-1:
                maxV.append(nums[front])

        return maxV

# nums = [1,3,-1,-3,5,3,6,7] 
# nums = [1,3,5,3,6,7] 
nums = [1,2,3,4,5,6] 
k = 1
s = Solution()
res = s.maxSlidingWindow(nums,k)
print(res)