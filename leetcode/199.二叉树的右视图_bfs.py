'''
本题中的这个数组是可以省略的
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import List
from queue import Queue

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        if root is None:
            return res
        self.bfs(root,res)
        print(res)


    def bfs(self,root,res):
        que = Queue()
        tmp = []    
        tmp.append(root)
        while(len(tmp)):            
            for i in tmp:
                que.put(i) # 放入每个值            
            res.append(i.val)
            tmp.clear()
            while(que.qsize()):
                head = que.get() # 获取队首            
                if head.left is not None:
                    tmp.append(head.left)
                if head.right is not None:
                    tmp.append(head.right)
        
    # 使用广搜找出每层的最右侧节点即可

# node4 = TreeNode(4,None,None)
# node5 = TreeNode(5,None,None)
# node3 = TreeNode(3,None,node4)
# node2 = TreeNode(2,None,node5)
# node1 = TreeNode(1,node2,node3)



# node4 = TreeNode(4,None,None)
node5 = TreeNode(5,None,None)
node3 = TreeNode(3,None,None)
node2 = TreeNode(2,None,node5)
node1 = TreeNode(1,node2,node3)

node1 = None
s = Solution()
s.rightSideView(node1)
