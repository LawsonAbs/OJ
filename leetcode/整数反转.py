'''
如何判断存储的数已经超过了64位整数？先除再比较大小，这种思想还是很不错的。巧妙的做等价运算。
'''
class Solution:
    def reverse(self, x: int) -> int:
        # 对数字x进行反转
        res = 0
        INT_MAX = (2 << 30) - 1
        # INT_MIN = - (2 << 30)

        if x < 0 :
            flag = 1
            x= -x
        while (x):
            if(INT_MAX//10 >= res ): # 需要判断是否会超出界限 
                res= res * 10 + x%10  # 不能以这种方式计算
                x //= 10
            else:                
                return 0
        if flag :
            res *= -1
        return res


s = Solution()
s.reverse(1534236469)