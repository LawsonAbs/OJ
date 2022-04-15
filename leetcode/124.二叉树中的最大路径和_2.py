'''
找出最大的根节点的值即可
1. 还需要考虑节点正负值的情况
2. 路径不能包含重复节点

思想
1. 计算每个节点，以该节点为根节点树下的最长路径
2. 再比较加上每个节点的值的情况
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        # 使用一个全局变量，来更新最后的结果
        
        self.maxSum = float("-inf")

    def maxPathSum(self, root:TreeNode) -> int:        
        self.dfs(root)
        return self.maxSum

    # 深搜代码的各个返回值必须是有相同的含义
    def dfs(self,root):
        if root is None:
            return 0
        
        # 保证最大贡献者是大于 0 的
        left = max(self.dfs(root.left,),0)
        right = max(self.dfs(root.right),0)
        
        self.maxSum = max(self.maxSum,left+right+root.val)
        
        # 返回节点的最大贡献值
        return root.val + max(left,right) 


node2 = TreeNode(2,None,None)
node3 = TreeNode(3,None,None)
node1 = TreeNode(1,node2,node3)

# node5 = TreeNode(7,None,None)
# node4 = TreeNode(15,None,None)
# node3 = TreeNode(20,node4,node5)
# node2 = TreeNode(9,None,None)
# node1 = TreeNode(-10,node2,node3)

# node4 = TreeNode(2,None,None)
# node2 = TreeNode(2,None,None)
# node3 = TreeNode(-3,None,node4)
# node1 = TreeNode(1,node2,node3)

# 如果是只有一个节点的值
# node2 = TreeNode(-2,None,None)
# node1 = TreeNode(-1,node2,None)

s = Solution()
out = s.maxPathSum(node1)
print(out)
