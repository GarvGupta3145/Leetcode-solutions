 /*
    APPROACH:
    - Last element of postorder = root of current subtree.
    - Find root's index in inorder (use hashmap for O(1) lookup):
      left of index = left subtree, right of index = right subtree.
    - Use one postIdx pointer moving right-to-left in postorder.
      Since postorder = [left, right, root], build RIGHT subtree
      first, then LEFT, to keep postIdx aligned correctly.
    - Base case: inLeft > inRight -> return nullptr.


    TIME:  O(n)  -> hashmap gives O(1) root lookup in inorder
    SPACE: O(n)  -> O(n) hashmap + O(h) recursion stack (h = tree height)
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