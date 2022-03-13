'''
（1）使用 try-except 模块解决问题
（2）字串查找可以直接使用index函数
'''
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            idx = haystack.index(needle)
        except:
            return -1
        return idx

s = Solution()
print(s.strStr(haystack="",needle=""))