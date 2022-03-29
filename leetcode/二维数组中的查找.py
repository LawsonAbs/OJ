from typing import List


class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        # (x,y) 是坐标
        x = y = 0 # 初始化
        while( x< len(matrix) and x >=0 and matrix[x][y] <=target):
            # if (x+1 < len(matrix) and matrix[x+1][y] < target):
            x = x+1
        # print(matrix[x][y])

        # (matrix[x][y])
        x = x-1
        while( y>=0 and y<len(matrix[0]) and x< len(matrix) and x >=0 ):
            if matrix[x][y] == target:
                print(x,y)
                return True
            elif matrix[x][y] < target:
                y = y+1         
            else :
                x = x-1
        print(x,y)
        return False

s = Solution()
# matrix = [
#   [1,   4,  7, 11, 15],
#   [2,   5,  8, 12, 19],
#   [3,   6,  9, 16, 22],
#   [10, 13, 14, 17, 24],
#   [18, 21, 23, 26, 30]
# ]
matrix = [[1,2,3,5,6]]
target = 5

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        out = s.findNumberIn2DArray(matrix,target=7)
        print(matrix[i][j]+1,out)