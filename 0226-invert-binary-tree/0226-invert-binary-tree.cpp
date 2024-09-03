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
    void rec(TreeNode* root){
        if(!root) return;
        auto temp= root->left;
        root->left=root->right;
        root->right=temp;
        rec(root->left);
        rec(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        rec(root);
        return root;
    }
};