'''
思路：
回文串中有且仅有一个字符，它的数目是奇数，剩余的字符数都是偶数。根据这个特点就可以得到算法过程。
还是有一些测试用例需要注意的：
01. 如果一个原串中的字符个数是奇数，那么可以从中取偶数个字符
'''
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        length = 0
        a = Counter(s)
        print(a)
        flag = 0
        if len(a) == 1:
            return list(a.values())[0]
        for item in a.items():
            key,val = item
            if val%2 ==0:
                length += val
            elif val%2 == 1:
                if val > 2:
                    length += val-1
                flag = 1
        if flag:
            length +=1 
        return length

s = Solution()
str = "abcccdd"
print(s.longestPalindrome(str))