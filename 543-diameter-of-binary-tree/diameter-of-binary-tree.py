# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        stack = [root]
        mp = {None : (0, 0)} 

        while stack:
            node = stack[-1] # top of stack
            if node.left and node.left not in mp:
                stack.append(node.left)
            elif node.right and node.right not in mp:
                stack.append(node.right)
            else: # reached the "bottom"
                node = stack.pop()
                leftHeight, leftDia = mp[node.left]
                rightHeight, rightDia = mp[node.right]
                mp[node] = (1 + max(leftHeight, rightHeight), max(leftDia, rightDia, leftHeight + rightHeight))
        return mp[root][1]