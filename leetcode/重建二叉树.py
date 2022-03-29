from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            node = TreeNode(preorder[0]) # 返回节点
            return node
        
        cur_val = preorder[0]
        idx = inorder.index(cur_val) # 找到根下标
        
        left_preorder  = preorder[1:1+idx]
        right_preorder = preorder[1+idx:]

        left_inorder = inorder[0:idx]
        right_inorder = inorder[idx+1:]

        # 获取当前树的左右
        h1 = self.buildTree(left_preorder,left_inorder) # 创建左子树
        h2 = self.buildTree(right_preorder,right_inorder) 
        root = TreeNode(cur_val)
        root.left = h1
        root.right = h2
        
        return root

s = Solution()
# preOrder = [3,9,20,15,7]
# inOrder = [9,3,15,20,7]
preOrder = [9,20,3,15,7]
inOrder = [9,3,15,20,7]
s.buildTree(preOrder,inOrder)