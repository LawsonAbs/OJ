from typing import List

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        visit = [[0 for i in range(len(board[0]))] for j in range(len(board))]# 得到一个访问标记初始化
        # step1. 先找出各个边界上的的O值
        for j in range(len(board[0])):
            if board[0][j] == 'O': # 第一行
                visit[0][j] = 1
                self.dfs(0,j,board,visit)
            if board[len(board)-1][j] == 'O': # 最后一行
                visit[len(board)-1][j] = 1
                self.dfs(len(board)-1,j,board,visit)
        
        print(visit)
        # 遍历第一列&最后一列
        for i in range(1,len(board)-1):
            if board[i][0] == 'O': # 第一列
                visit[i][0] = 1
                self.dfs(i,0,board,visit)
            
            if board[i][len(board[0])-1] == 'O': # 最后一列
                visit[i][len(board[0])-1] = 1
                self.dfs(i,len(board[0])-1,board,visit)

        for i in range(len(board)):
            for j in range(len(board[0])):
                if visit[i][j] == 0:
                    board[i][j] = "X"    
        print(visit)
        return board
    
    # step2. 将边界上的点逐一深搜，深搜的参数是坐标
    def dfs(self,x,y,board,visit): 
        # 按照上下左右的顺序深搜
        if x-1>=0  and board[x-1][y] == 'O' and visit[x-1][y] == 0: # (x-1,y)
            visit[x-1][y] = 1
            self.dfs(x-1,y,board,visit)
            
        if x+1<len(board) and board[x+1][y] == 'O' and visit[x+1][y] == 0: # (x+1,y)
            visit[x+1][y] = 1
            self.dfs(x+1,y,board,visit)
        if y-1>=0 and board[x][y-1] == 'O' and visit[x][y-1] == 0: # (x,y-1)
            visit[x][y-1] = 1
            self.dfs(x,y-1,board,visit)

        if y+1 < len(board[0]) and board[x][y+1] == 'O' and visit[x][y+1] ==0 : # (x,y+1)
            visit[x][y+1] = 1
            self.dfs(x,y+1,board,visit)
        
# board = [["X","O","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
# board = [["X","O","X","X"]]
board = [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
s = Solution()
out = s.solve(board)
print(out)
