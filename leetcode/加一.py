'''
1.python中的整除是 //
2.使用 insert 解决插入问题

'''
from typing import List
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        flag = 1 # 末位要加一

        for i in range(len(digits)-1,-1,-1): # 使用range 逆序输出整个数组
            if flag: # 如果有进位
                digits[i] += 1 
                flag = 0 # 重置
            if digits[i] >= 10: # 如果下面存在进位                
                flag = digits[i]//10   # 必须是整除，所以这里用 //
                digits[i] -= 10
        
        if flag:            
            digits.insert(0,flag) 
        
        # for i in digits:
        #     print(i,end= "")
        print(digits)


s = Solution()
digits = [9,9,1,0]
s.plusOne(digits)