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
    int  solve(TreeNode*root,int k,int &count){
        int ans=-1;
        if(!root){
            return -1;
        }
        ans= solve(root->left,k,count);
        if(count==k)return ans;
        count++;
        if(count==k){
            ans=root->val;
            return ans;
        }
        ans= solve(root->right,k,count);
        if(count==k)return ans;
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int small=solve(root,k,count);
        return small;
    }
};