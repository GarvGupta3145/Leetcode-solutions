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
    void build(TreeNode*root,TreeNode*&prev){
        if(!root)return;
        build(root->right,prev);
        if(prev){
            root->val=root->val+prev->val;
        }
        prev=root;
        build(root->left,prev);
    }
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* prev=NULL;
        build(root,prev);
        return root;
    }
};