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
    void ans(TreeNode*root,vector<int>&inorder){
        if(!root)return;
        ans(root->left,inorder);
        inorder.push_back(root->val);
        ans(root->right,inorder);
    }
    int binary(vector<int>& inorder,int num){
        int low=0;
        int high=inorder.size()-1;
        int mid=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(inorder[mid]>num){
                high=mid-1;
            }
            else if(inorder[mid]<num)low=mid+1;
            else return mid;
        }
        return mid;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>inorder;
        vector<vector<int>>res(queries.size(),vector<int>(2, -1));
        ans(root,inorder);
        int n=inorder.size();
        for(int i=0;i<queries.size();i++){
            int mid=binary(inorder,queries[i]);
            if(inorder[mid]!=queries[i]){
                int left,right;
                if(inorder[mid]<queries[i]){
                    res[i][0]=inorder[mid];
                    int k=mid;
                    while(k<n && inorder[k]==inorder[mid]){
                        k++;
                    }
                    if(k==n)res[i][1]=-1;
                    else res[i][1]=inorder[k];

                }
                else{
                    res[i][1]=inorder[mid];
                    int k=mid;
                    while(k>=0 && inorder[k]==inorder[mid]){
                        k--;
                    }
                    if(k<0)res[i][0]=-1;
                    else res[i][0]=inorder[k];
                }
            }
            else{
                res[i][0]=inorder[mid];
                res[i][1]=inorder[mid];
            }
        }
        return res;
    }
};