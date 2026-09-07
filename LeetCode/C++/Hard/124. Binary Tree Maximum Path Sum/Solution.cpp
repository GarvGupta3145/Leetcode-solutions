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
    int path(TreeNode* root,int &mpath){
        if(!root)return 0;
        int lchild=path(root->left,mpath);
        int curr=root->val;
        if(lchild>0)curr+=lchild;
        mpath=max(mpath,curr);
        int rchild=path(root->right,mpath);
        if(rchild>0)curr+=rchild;
        mpath=max(mpath,curr);
        if(lchild>0||rchild>0)return root->val+max(lchild,rchild);\
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        int mpath=INT_MIN;
        int h= path(root,mpath);
        return mpath;
    }
};