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
    TreeNode* CreateNode(TreeNode*root,int val){
        TreeNode* newnode=new TreeNode(val);
        return newnode;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root=CreateNode(root,val);
            return root;
        } 
        TreeNode*curr=root;
        while(1){
            if(curr->val>val){
                if(curr->left==NULL){
                    curr->left=CreateNode(curr,val);
                    break;
                }
                curr=curr->left;
            }
            else{
                if(curr->right==NULL){
                    curr->right=CreateNode(curr,val);
                    break;
                }
                curr=curr->right;
            }
        }
        return root;
    }
};