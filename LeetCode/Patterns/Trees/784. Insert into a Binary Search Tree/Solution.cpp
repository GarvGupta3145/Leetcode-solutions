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
    TreeNode* createNode(int val){
        TreeNode* node= new TreeNode(val);
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node=createNode(val);
            return node;
        }
        TreeNode*curr=root;
        while(1){
            if(curr->val<val){
                if(!curr->right){
                    TreeNode* node=createNode(val);
                    curr->right=node;
                    return root;
                }
                else curr=curr->right;
            }
            else{
                if(!curr->left){
                    TreeNode* node=createNode(val);
                    curr->left=node;
                    return root;
                }
                else curr=curr->left;
            }
        }
    }
};