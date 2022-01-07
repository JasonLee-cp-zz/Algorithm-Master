# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        def help(root):
            if root is None:
                return None
            
            if root.val == val:
                return root
            
            if val > root.val:
                return help(root.right)
            else:
                return help(root.left)
            
        return help(root)