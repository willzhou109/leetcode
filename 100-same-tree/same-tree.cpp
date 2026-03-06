/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        } else if (!s || !t) {
            return false;
        } else if (s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right)) {
            return true;
        }
        return false;
    }
};