from typing import List 

'''
想法1.先搜行，再搜列
想法2.先按照行递增遍历，如果超过指定数了，接着就行坐标减一，往列下标增长的方向遍历。如果超过了，则y--。直到最终找到这个值。
'''
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        first_column = [matrix[i][0] for i in range(len(matrix))] # 拿到[:,0] 该列
        # print(first_column)
        row_idx = self.bin_search(first_column,target,low=0,high=len(first_column)-1) # row[row_idx] <= target        
        first_row = [matrix[0][i] for i in range(len(matrix[0]))] # 拿到[0,:] 该行
        col_idx = self.bin_search(first_row,target,low=0,high=len(first_row)-1)
        print(row_idx,col_idx)

        for i in range(row_idx+1):
            for j in range(col_idx+1):
                if matrix[i][j] == target:
                    # print(f"i={i},j={j}")
                    return True
        return False

    def bin_search(self,row,target,low,high): 
        while(low < high):
            mid = (low+high) // 2
            if (row[mid] < target):
                low = mid+1
            elif row[mid] > target:
                high = mid-1
            elif row[mid] == target:
                return mid
        return min(low,high) # 返回二者较小值


s = Solution()
# matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]

# target = [5,10,15,29,32,43]

matrix = [[-1,3]]
target = [3]
for i in target:
    print(s.searchMatrix(matrix,i))