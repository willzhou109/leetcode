#include <climits>
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
private:
     bool dfs(TreeNode* root, long min, long max) {
        if (!root) return true;
        if ((long)root->val <= min || (long)root->val >= max) return false;
        return dfs(root->left, min, (long)root->val) && dfs(root->right, (long)root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN - long(1), INT_MAX + long(1));
    }
};