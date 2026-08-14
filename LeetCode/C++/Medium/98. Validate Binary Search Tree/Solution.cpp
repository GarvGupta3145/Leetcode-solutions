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
    bool isValidBSTHelper(TreeNode* root, long &subMin, long &subMax) {
        if (!root) return true; // empty subtree, no min/max to set here

        long lmin, lmax, rmin, rmax;
        bool leftValid = true, rightValid = true;

        if (root->left) {
            leftValid = isValidBSTHelper(root->left, lmin, lmax);
            if (!leftValid || root->val <= lmax) return false;
        }

        if (root->right) {
            rightValid = isValidBSTHelper(root->right, rmin, rmax);
            if (!rightValid || root->val >= rmin) return false;
        }

        // propagate this subtree's min/max upward
        subMin = root->left ? lmin : root->val;
        subMax = root->right ? rmax : root->val;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        long dummyMin, dummyMax;
        return isValidBSTHelper(root, dummyMin, dummyMax);
    }
};