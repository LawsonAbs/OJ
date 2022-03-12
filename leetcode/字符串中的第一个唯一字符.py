'''
方法1：使用Counter 对字符串的数字进行统计，然后找出其中值为1的元素的下标即可。

'''
from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        # 返回索引
        idx = -1
        a = Counter(s)        
        print(a)
        for item in a.items():
            key,val = item
            if val == 1:
                
                return  (s.index(key))
        return idx

s = Solution()
s.firstUniqChar("leetcode")