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
        path = []
        res = []
        tot = 0 # 当前路径和        
        self.dfs(root,targetSum,path,tot,res)
        return res

    def dfs(self,root,targetSum,path,tot,res):        
        if root is not None:
            tot+=root.val
            path.append(root.val)
        else: #  如果是None，肯定要返回
            return        
        if tot == targetSum and root.left is None and root.right is None:            
            res.append(copy(path)) # 放入路径信息
            # 如果程序是从这里结束而不是最下面的path.pop()结束，所以就需要把上面path.append()的操作给对应复位
            path.pop()
            return
        self.dfs(root.left,targetSum,path,tot,res)
        self.dfs(root.right,targetSum,path,tot,res)
        path.pop()  # 与上面的path.append(root.val) 相对应



node3 = TreeNode(2,None,None)
node2 = TreeNode(2,None,None)
node1 = TreeNode(1,node2,node3)
targetSum = 3

s = Solution()
out = s.pathSum(node1,targetSum)
print(out)