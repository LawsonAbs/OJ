class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        
        n,b = divmod(n,2)    
        # print(n,b)
        # 将n转换为2进制
        while(n):            
            n,c = divmod(n,2)
            if (b == 0 and c == 1 ): # 交换值
                b,c = c,b
            elif(b == 1 and c == 0):
                b,c = c,b
            else:
                return False
        return True


s = Solution()
for i in range(1,20):
    out = s.hasAlternatingBits(i)
    print(i,out)  