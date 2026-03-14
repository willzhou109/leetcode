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
    int dfs(TreeNode* root, int curr_path_max) { // returns the number of good nodes under the root
        if (!root) {
            return 0;
        }
        if (root->val >= curr_path_max) {
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        } else {
            return dfs(root->left, curr_path_max) + dfs(root->right, curr_path_max);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
