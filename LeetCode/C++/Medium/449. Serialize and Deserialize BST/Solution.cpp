/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        string s=to_string(root->val)+',';
        if(root->left)s+=serialize(root->left);
        if(root->right)s+=serialize(root->right);
        return s;
    }

    TreeNode * build(string &preorder, int &i,int bound){
        if(i>=preorder.size())return NULL;
        int save=i;
        int val=0;
        bool neg=false;
        while(preorder[i]!=','){
            if(preorder[i]=='-')neg=true;
            else val=val*10+preorder[i]-'0';
            i++;
        }
        if(neg)val*=-1;
        if(val>bound){
            i=save;
            return NULL;
        }
        i++;
        TreeNode* root= new TreeNode(val);
        root->left=build(preorder,i,val);
        root->right=build(preorder,i,bound);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return build(data, i,INT_MAX);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;