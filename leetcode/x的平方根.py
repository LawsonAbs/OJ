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