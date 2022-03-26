from math import remainder
from typing import List

'''
使用递归的方法来解决螺旋矩阵的问题
'''
class Solution:
    def __init__(self):
        self.res = []

    def spiralOrder(self, matrix: List[List[int]],row_low,row_high,col_left,col_right) -> List[int]:
        if (row_high <= row_low) or (col_left >= col_right):
            return [] # 返回一个空列表
        if (row_low + 1 == row_high): # 只有一行
            return [matrix[row_low][j] for j in range(col_left,col_right)] # 加入第一行
        if ( col_left +1 == col_right): # 只有一列
            return [matrix[j][col_left] for j in range(row_low,row_high)] # 加入第一列
        self.res.extend([matrix[row_low][j] for j in range(col_left,col_right)]) # 加入第一行
        self.res.extend(matrix[i][col_right-1] for i in range(row_low+1,row_high-1)) # 加入最后一列 [掐头去尾]
        self.res.extend(matrix[row_high-1][i] for i in reversed(range(col_left,col_right))) # 加入最后一行
        self.res.extend(matrix[i][0] for i in reversed(range(row_low+1,row_high-1))) # 加入第一列【掐头去尾】
        # remainder = [matrix[i][j] for i in range(row_low+1,row_high-1) for j in range(col_left+1,col_right-1)]
        self.res.extend(self.spiralOrder(matrix,row_low+1,row_high-1,col_left+1,col_right-1))
        return self.res

s = Solution()

# matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
# matrix = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
# matrix = [[1,2,3,4,5,6],[7,8,9,10,11,12]]
# matrix = [[1,2],[3,4],[5,6],[7,8],[9,10],[11,12]]
matrix  =[[1,2,3,4]]
# row_high 到不了
# col_right 到不了
res = s.spiralOrder(matrix,row_low=0,row_high=len(matrix),col_left=0,col_right=len(matrix[0]))
print(res)
