/**
 * APPROACH 3: Reverse PostOrder
               right left root
 */
class Solution {
public:
    void solve(TreeNode*root,TreeNode* &prev){
        if(!root)return;
        solve(root->right,prev);
        solve(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
        return;
    }
    void flatten(TreeNode* root) {
        TreeNode*prev=NULL;
        solve(root,prev);
    }
};