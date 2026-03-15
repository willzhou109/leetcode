#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector;
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
    void inorder_DFS(TreeNode* root, vector<int>* nodes_ptr) {
        if (root == nullptr) return;
        inorder_DFS(root->left, nodes_ptr);
        (*nodes_ptr).emplace_back(root->val);
        inorder_DFS(root->right, nodes_ptr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes_vector = {};
        inorder_DFS(root, &nodes_vector);
        return nodes_vector[k - 1];
    }
};