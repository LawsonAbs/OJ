'''
二分法中，如果high和low只有一个变化，那么很有可能就无法跳出循环。所以这里 一般的都是 high = mid-1, low = mid+ 1
'''
class Solution:
    def mySqrt(self, x: int) -> int:        
        if x == 0: # 需要注意特殊用例
            return x
        low = 0
        high = 2**16
        while(low< high):
            mid = (low+high) // 2
            if x/mid < mid : 
                high = mid-1 # 不可能取mid
            
            # 这里如果 取low = mid+1 很有可能就错过答案了。所以后面再来一个if-else 进行判断
            elif x/mid > mid: 
                low = mid+1
            elif x/mid == mid:
                return mid
        if x/low >= low:
            return low 
        elif x/low < low:
            return low-1

s = Solution()
for i in range(0,1):
    print(i,s.mySqrt(i))