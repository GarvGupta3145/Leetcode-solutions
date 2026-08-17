class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return solve(root, k, seen);
    }

    bool solve(TreeNode* root, int k, unordered_set<int>& seen) {
        if(!root) return false;
        if(seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return solve(root->left, k, seen) || solve(root->right, k, seen);
    }
};