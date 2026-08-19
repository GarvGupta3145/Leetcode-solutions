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
    void pushLeft(stack<TreeNode*>&st,TreeNode*root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>st1,st2;
        pushLeft(st1,root1);
        pushLeft(st2,root2);
        vector<int>ans;
        while(!st1.empty() && !st2.empty()){
            if(st1.top()->val<=st2.top()->val){
                TreeNode*curr=st1.top();
                st1.pop();
                ans.push_back(curr->val);
                if(curr->right)pushLeft(st1,curr->right);
            }
            else{
                TreeNode*curr=st2.top();
                st2.pop();
                ans.push_back(curr->val);
                if(curr->right)pushLeft(st2,curr->right);
            }
        }
        while(!st1.empty()){
            TreeNode*curr=st1.top();
            st1.pop();
            ans.push_back(curr->val);
            if(curr->right)pushLeft(st1,curr->right);
        }
        while(!st2.empty()){
            TreeNode*curr=st2.top();
            st2.pop();
            ans.push_back(curr->val);
            if(curr->right)pushLeft(st2,curr->right);
        }
        return ans;
    }
};