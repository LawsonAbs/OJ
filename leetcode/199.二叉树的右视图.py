class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

from typing import List

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:   
        if root is None:
            return []
        # 深搜找结果
        res = {}
        self.dfs(root,0,res)
        out = list(res.values())
        return out

    # 依次遍历左右两棵子树
    def dfs(self,root,height,res):
        if root is None:
            return
        
        res.setdefault(height, root.val)
        # 先遍历右子树
        self.dfs(root.right,height+1,res)
        self.dfs(root.left,height+1,res)


# node4 = TreeNode(4,None,None)
# node3 = TreeNode(3,None,None)
# node2 = TreeNode(2,None,node4)
# node1 = TreeNode(1,node2,node3)

node4 = TreeNode(4,None,None)
node5 = TreeNode(5,node4,None)
node3 = TreeNode(3,None,None)
node2 = TreeNode(2,None,node5)
node1 = TreeNode(1,node2,node3)

s = Solution()
out = s.rightSideView(node1)
print(out)