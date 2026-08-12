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
    void dfs(TreeNode* root,vector<TreeNode*>&preorder){
        if(!root){
            return;
        }
        preorder.push_back(root);
        dfs(root->left,preorder);
        dfs(root->right,preorder);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        vector<TreeNode*>preorder;
        dfs(root,preorder);
        for(int i=1;i<preorder.size();i++){
            preorder[i-1]->left=NULL;
            preorder[i-1]->right=preorder[i];
        }
    }
};