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
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        if(!root->left && !root->right)return true;
        if(!root->left && root->right){
            return isValidBST(root->right);
        }
        else if(!root->right && root->left){
            return isValidBST(root->left);
        }
        if(root->val > root->left->val && root->val < root->right->val){
            bool left=isValidBST(root->left);
            bool right=isValidBST(root->right);
            if(left && right)return true;
            else return false;
        }
        else return false;
    }
};