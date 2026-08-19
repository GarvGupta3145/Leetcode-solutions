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
    void build(TreeNode* root, TreeNode* &prev){
        if(!root)return;
        build(root->left,prev);
        if(prev){
            prev->right=root;
            prev->left=NULL;
        }
        prev=root;
        build(root->right,prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode*curr=root;
        while(curr->left){
            curr=curr->left;
        }
        build(root,prev);
        return curr;
    }
};