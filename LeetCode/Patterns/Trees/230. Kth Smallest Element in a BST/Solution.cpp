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
    
    int solve(TreeNode* root, int k, int &count) {
        if (!root) return -1;

        int ans = solve(root->left, k, count);
        if (count == k) return ans;

        count++;
        if (count == k) return root->val;

        ans = solve(root->right, k, count);
        if (count == k) return ans;

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return solve(root, k, count);
    }
};