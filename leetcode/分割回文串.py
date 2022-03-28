from typing import List
from copy import copy
'''
每个子串都得是回文串
'''

class Solution:

    def partition(self, s: str) -> List[List[str]]:
        tmp = []  # 可行解
        res = []# 存储最后的结果
        self.dfs(s,0,tmp,res)
        return res

    # 深搜找出合适的子串作为结果
    # have_len 表示已经找到的回文子串的总长度
    def dfs(self,s,have_len,tmp,res):
        if have_len == len(s): # 找到了一个满足条件的输出
            res.append(copy(tmp))
        # 找一个长度为i的子串，并判断是否回文， i的长度会有一个限制
        # i的范围是 从1 到整个len(s)
        cur = "" # 初始为空
        for i in range(have_len,len(s)): 
            cur += s[i]
            if len(cur) and self.is_palindrome(cur): # 如果是个回文串，满足条件
                tmp.append(cur)
                self.dfs(s,have_len+len(cur),tmp,res)
                del tmp[-1]

    # 判断字符串是否回文
    def is_palindrome(self,s):
        left = 0
        right = len(s) - 1
        while(left < right):
            if s[left] != s[right]:
                return False
            left+=1
            right-=1    
        return  True

s = Solution()
s1 = "aba"
res = s.partition(s1)
print(res)