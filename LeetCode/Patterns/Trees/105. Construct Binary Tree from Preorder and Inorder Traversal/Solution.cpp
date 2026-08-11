// ** APPROACH **


// Preorder's first element is always the root of the (sub)tree.
// Find that root's position in inorder using a value->index map (O(1) lookup).
// Everything left of it in inorder = left subtree, everything right = right subtree.
// leftSize = number of nodes in left subtree = rootind - st
// Left subtree's preorder segment starts right after root: i+1
// Right subtree's preorder segment starts after root + entire left subtree: i+1+leftSize
// Recurse until the inorder range becomes invalid (st > end) -> base case

class Solution {
public:
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>& mpp, int i, int st, int end) {
        if (st > end) return NULL;

        int rootind = mpp[preorder[i]];
        int leftSize = rootind - st;

        TreeNode* root = new TreeNode(preorder[i]);
        root->left = build(preorder, mpp, i + 1, st, rootind - 1);
        root->right = build(preorder, mpp, i + 1 + leftSize, rootind + 1, end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        return build(preorder, mpp, 0, 0, n - 1);
    }
};