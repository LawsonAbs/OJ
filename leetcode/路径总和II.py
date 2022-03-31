from typing import List
from copy import copy
'''
需要注意的几点：
1.如果树为空，直接返回
2.达到输出的条件是：从根节点到叶子节点
3.值可能不一定只是正整数，也有可能是小数，所以不能因为其它原因提前终止dfs
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        if root is None: 
            return []
        # root 当前正在访问的节点
        # path 路径信息
        # res 最后的结果
        path = [root.val]
        res = []
        tot = root.val # 当前路径和        
        self.dfs(root,targetSum,path,tot,res)
        return res

    def dfs(self,root,targetSum,path,tot,res):        
        if tot == targetSum and root.left is None and root.right is None:            
            res.append(copy(path)) # 放入路径信息
            return 
               
        if root.left is not None:
            path.append(root.left.val)
            self.dfs(root.left,targetSum,path,tot+root.left.val,res)
            path.pop() 

        if root.right is not None:
            path.append(root.right.val)
            self.dfs(root.right,targetSum,path,tot+root.right.val,res)
            path.pop()


node4 = TreeNode(-1,None,None)
node3 = TreeNode(1,node4,None)
node2 = TreeNode(-2,node3,None)
node1 = TreeNode(1,node2,None)
targetSum = -1

s = Solution()
out = s.pathSum(node1,targetSum)
print(out)