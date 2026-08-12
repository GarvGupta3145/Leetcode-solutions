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
    TreeNode* build(vector<int>&postorder,unordered_map<int,int>&mp,int i,int st,int end){
        if(st>end)return NULL;

        int rootind=mp[postorder[i]];
        int right_size=end-rootind;
        TreeNode*root=new TreeNode(postorder[i]);
        root->left=build(postorder,mp,i-1-right_size,st,rootind-1);
        root->right=build(postorder,mp,i-1,rootind+1,end);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=postorder.size();
        return build(postorder,mp,n-1,0,n-1);
    }
};