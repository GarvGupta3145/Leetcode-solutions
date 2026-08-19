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
    void find(vector<int>& ans,TreeNode*&prev,TreeNode* root,int &count,int & mx){
        if(!root)return;
        find(ans,prev,root->left,count,mx);
        if(prev && prev->val !=root->val){
            while(!ans.empty() && mx<count){
                ans.pop_back();
            }
            if(ans.empty()||mx==count)ans.push_back(prev->val);
            if(count>mx)mx=count;
            count=0;
        }
        count++;
        prev=root;
        if(root->right)find (ans,prev,root->right,count,mx);
        
    }
    vector<int> findMode(TreeNode* root) {
        int mx=0;
        int count=0;
        vector<int>ans;
        TreeNode* prev=NULL;
        find(ans,prev,root,count,mx);
        while(!ans.empty() && mx<count){
            ans.pop_back();
        }
        if(ans.empty()||mx==count)ans.push_back(prev->val);
        if(count>mx)mx=count;
        count=0;
        
        return ans;
    }
};