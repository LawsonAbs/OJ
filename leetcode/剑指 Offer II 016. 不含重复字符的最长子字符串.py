'''
不重复字符的  最长连续字符串
思想
（1）有那么一丢丢像是双指针
'''
from collections import Counter
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        span = []
        res = 0
        left = right = 0
        for right in range(len(s)):
            if s[right] not in span:
                span.append(s[right])
                res = max(res,len(span))
            else:
                while(s[right] in span):
                    span.remove(s[left])
                    left+=1
                span.append(s[right])
        return res

s = Solution()
s.lengthOfLongestSubstring("abcabcbb")