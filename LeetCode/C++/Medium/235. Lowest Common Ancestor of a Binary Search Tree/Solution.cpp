/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode*root,int sm,int target , bool &found,TreeNode* &common){
    if(!found){
        if(root->val<sm) solve(root->right,sm,target,found,common);
        else if(root->val>sm) solve(root->left,sm,target,found,common);
        else { found=true; return false; }
    }
    if(!found) return false;

    if(root->val==target){ if(!common) common=root; return true; }   // <-- added

    bool lf=false,rf=false;
    lf=dfs(root->left,target);
    if(!lf && root->val<target){
        rf=dfs(root->right,target);
        if(rf){
            if(!common) common=root;
            return true;
        }
        return false;
    }
    return true;
}
    bool dfs(TreeNode*root, int target){
        if(!root)return false;
        TreeNode * curr=root;
        while(curr){
            if(curr->val == target )return true;
            else if(curr->val<target)curr=curr->right;
            else curr=curr->left;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv=p->val;
        int qv=q->val;
        int sv;
        TreeNode* s= pv<qv?p:q;
        int target= p->val>q->val ? p->val:q->val;
        sv=s->val;
        if(dfs(s->right,target))return s;
        TreeNode* common = nullptr;
        bool sf=false;
        solve(root,sv,target,sf,common);
        return common;
    }
};