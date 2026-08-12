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
        if(!root)return "n,";
        string s=to_string(root->val)+',';
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    //s="1,2,n,n,3,4,n,n,5,n,n"

    TreeNode* solve(string s,int &i){
        if(i==s.size())return NULL;
        if(s[i]==',')i++;
        if(s[i]=='n'){
            i++;
            return NULL;
        }
        int val=0;
        bool neg=false;
        while(s[i]!=','){
            if(s[i]=='-')neg=true;
            else val=val*10+s[i]-'0';
            i++;
        }
        if(neg)val*=-1;
        i++;
        TreeNode* root= new TreeNode(val);
        root->left=solve(s,i);
        root->right=solve(s,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return solve(data,i);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));