from typing import List

class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        inorder = sorted(postorder) # 得到中序序列       
        return self.dfs(postorder,inorder)
    
    # 需要满足的条件是：根比所有左子树节点大，根比所有右子树节点小
    def dfs(self,postorder,inorder):
        if len(postorder) == 1 or len(postorder) == 0:
            return True
        
        root = postorder[-1] # 得到根节点
        idx = inorder.index(root)
    
        # 轮流得到左右子树的中序序列
        left_inorder = inorder[0:idx]
        right_inorder = inorder[idx+1:]
        
        left_postorder = postorder[0:idx]
        right_postorder = postorder[idx:-1]

        # 判断根节点是否大于左侧
        for i in left_postorder:
            if i > root:
                return False
        
        for i in right_postorder:
            if i < root:
                return False
        
        if self.dfs(left_postorder,left_inorder) and self.dfs(right_postorder,right_inorder):
            return True
        return False


# postorder = [1,6,3,2,5]
postorder = [1,3,2,6,5]
postorder=[1]
postorder = [2,1]
s = Solution()
out = s.verifyPostorder(postorder)
print(out)