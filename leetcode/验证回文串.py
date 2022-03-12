'''
（1）python中字符串翻转使用 reversed() 函数
(2)可以使用 .lower() .upper() 函数转换字符串的大小写
'''
class Solution:
    def isPalindrome(self, s: str) -> bool:        
        # 过滤掉非数字+字母 的字符
        s = s.lower() 
        b =""
        for i in s:
            if i >='a'  and i <= 'z' :
                b+=i
            if i in ['0','1','2','3','4','5','6','7','8','9'] :
                b+=i
            
        tmp = b
        # reversed() 得到的结果是一个类似迭代器的东西，需要 使用"".join 进行拼接
        c = "".join(reversed(b))
        # print(b)
        # print(c)
        return c == tmp # 判断二者是否相等

s = Solution()
s.isPalindrome('A ma, a plan, a canal: Panama')