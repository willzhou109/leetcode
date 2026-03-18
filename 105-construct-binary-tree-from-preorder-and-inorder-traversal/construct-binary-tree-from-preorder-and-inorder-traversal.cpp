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
    /**
    * @brief returns a binary tree based on the root node, and the range
    * of indices in the inorder vector. Note the root node divides the range
    * into two halves. Uses preorder traversal.
    * @param preorder preorder vector
    * @param preorder_idx current index in the preorder vector
    * @param inorder_hm inorder hashmap
    * @param start_idx start of range in inorder vector
    * @param end_idx end of range in inorder vector
    * @return the resulting tree of that root
    */
    TreeNode* buildTree_dfs(vector<int>& preorder, int* preorder_idx, map<int, int>& inorder_hm, int start_idx, int end_idx) {
        if (*preorder_idx >= preorder.size() || start_idx > end_idx) return nullptr;
        int root_val = preorder[*preorder_idx]; // root node's value, which is obtained from the preorder vector
        int root_idx = inorder_hm[root_val]; // root index, obtained from hashmap
        TreeNode* root = new TreeNode(root_val);
        *preorder_idx += 1;
        root->left = buildTree_dfs(preorder, preorder_idx, inorder_hm, start_idx, root_idx - 1);
        root->right = buildTree_dfs(preorder, preorder_idx, inorder_hm, root_idx + 1, end_idx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // convert inorder to a hashmap
        map<int, int> inorder_hm;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_hm[inorder[i]] = i;
        }
        int *preorder_count = new int();
        return buildTree_dfs(preorder, preorder_count, inorder_hm, 0, inorder.size() - 1);
    }
};
