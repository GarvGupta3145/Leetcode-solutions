/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
       
 * };
 */
class Solution {
public:
    bool valid(TreeNode* root, int &subMin,int &subMax,int &csum,int &sum){
        if(!root->left &&!root->right){
            subMin=root->val;
            subMax=root->val;
            csum=root->val;
            sum= max(sum,csum);
            return true;
        }
        bool lf=true,rf=true;
        int lmin,lmax,rmin,rmax;
        int lsum=0,rsum=0;
        if(root->left)lf=valid(root->left,lmin,lmax,lsum,sum);
        else{
            lmax=INT_MIN;
            lmin=root->val;;
        }
        if(root->right)rf=valid(root->right,rmin,rmax,rsum,sum);
        else{
            rmin=INT_MAX;
            rmax=root->val;
        }
        if(lf && rf){
            if(root->val> lmax && root->val<rmin){
                csum=lsum+rsum+root->val;
                sum= max(sum,csum);
                subMin=lmin;
                subMax=rmax;
                return true;
            }
            
        }
        subMin = INT_MIN;
        subMax = INT_MAX;
        return false;
    }
    int maxSumBST(TreeNode* root) {
        int sum=0;
        int subMin=INT_MIN;
        int subMax=INT_MAX;
        int csum=0;
        valid(root,subMin,subMax,csum,sum);
        return sum;
    }
};