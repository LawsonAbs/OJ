'''
（1）python中字符串翻转使用 reversed() 函数
(2)可以使用 .lower() .upper() 函数转换字符串的大小写
'''
class Solution:
    def isPalindrome(self, s: str) -> bool:        
        tmp = s
        # reversed() 得到的结果是一个类似迭代器的东西，需要 使用"".join 进行拼接
        c = "".join(reversed(s))
        print(tmp)
        print(c)

s = Solution()
s.isPalindrome('AI is a interest thing')