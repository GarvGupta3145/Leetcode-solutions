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
    void find(TreeNode* root, TreeNode* &prev,int & mn){
        if(!root)return;
        find(root->left,prev,mn);
        if(prev){
            int diff=abs(root->val - prev->val);
            mn=min(mn,diff);
        }
        prev=root;
        find(root->right,prev,mn);
    }
    int getMinimumDifference(TreeNode* root) {
        int mn=INT_MAX;
        TreeNode* prev=NULL;
        find(root,prev,mn);
        return mn;
    }
};