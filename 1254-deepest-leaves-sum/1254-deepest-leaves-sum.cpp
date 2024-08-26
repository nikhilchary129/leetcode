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
    int ans=0;
    int maxdept=0;
    int dept(TreeNode* root){
        if(! root) return 0;

        return max(dept(root->left),dept(root->right))+1;
    }
    void dfs(TreeNode* root,int level){
        if(!root)return;
        if(level==maxdept){
            ans+=root->val;
            return;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        

    }
    int deepestLeavesSum(TreeNode* root) {
        maxdept= dept(root);
        dfs(root,1);
        return ans;
    }
};