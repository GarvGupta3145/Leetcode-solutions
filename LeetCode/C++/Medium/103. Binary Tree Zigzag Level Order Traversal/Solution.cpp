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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        ans.push_back({root->val});
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        bool flag=false;
        while(!q.empty()){
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                if(node->left){
                    temp.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right){
                    temp.push_back(node->right->val);
                    q.push(node->right);
                }
                q.pop();
            }
            if(!temp.empty()){
                if(flag)ans.push_back(temp);
                else {
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                }
            }
            flag=!flag;
        }
        return ans;
    }
};