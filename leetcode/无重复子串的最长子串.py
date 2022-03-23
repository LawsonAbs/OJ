'''
这里的测试样例如 abba, dvdf。
对于字符串的题，找够测试样例，然后注意边界条件就够了
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        res = [1] * len(s) # 初始化为1
        hash = set()
        hash.add(s[0]) # 加入第一个字符
        idx = {} # 记录字符首次出现的位置
        idx[s[0]] = 0
        for i in range(1,len(s)):
            if s[i] not in hash:
                res[i] = res[i-1] + 1                
            else:
                #  这个地方应该对 res[i] 进行赋值， 注意这里是用min
                res[i] = min(i - idx[s[i]],res[i-1]+1)  
            idx[s[i]] = i
            hash.add(s[i])
        # print(res)
        max_val = 1
        for i in res:
            max_val = max(max_val,i)
        return max_val