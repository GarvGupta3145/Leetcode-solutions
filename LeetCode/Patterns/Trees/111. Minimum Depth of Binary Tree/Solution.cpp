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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int count=1;
        while(root->left && !root->right){
            if(root->left)root=root->left;
            count++;
        }
        if(root->right)count=1;
        while(root->right && !root->left){
            if(root->right)root=root->right;
            count++;
        }
        if(root->left)count=1;
        if(count!=1)return count;
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};