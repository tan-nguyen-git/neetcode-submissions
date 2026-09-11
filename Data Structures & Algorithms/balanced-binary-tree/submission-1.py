# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
       
        def dfs(curr):
            if not curr:
                return 0

            left = dfs(curr.left)
            #already unbalance
            if(left == -1):
                return -1
            right= dfs(curr.right)
             #already unbalance
            if(right == -1):
                return -1
            if abs(left - right) >1 :
                #return -1 if unbalance
                return -1
            
            return 1 + max(left , right)
        dfs(root)

        return dfs(root) != -1

    