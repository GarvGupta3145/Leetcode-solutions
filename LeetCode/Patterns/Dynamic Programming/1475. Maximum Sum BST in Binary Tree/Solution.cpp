class Solution {
public:
    // Approach:
    // A subtree rooted at 'root' is a valid BST if and only if:
    //   1. Its left subtree is a valid BST
    //   2. Its right subtree is a valid BST
    //   3. root->val > (max value in left subtree)
    //   4. root->val < (min value in right subtree)
    // So we do a POST-ORDER (bottom-up) traversal: process children first,
    // then use their results to validate the current node.
    //
    // For each node we compute/return 4 things:
    //   - isBST : whether this subtree is a valid BST
    //   - subMin: minimum value in this subtree (needed by parent's ">" check)
    //   - subMax: maximum value in this subtree (needed by parent's "<" check)
    //   - csum  : sum of this subtree (only meaningful if isBST is true)
    //
    // If a child doesn't exist, we use INT_MIN (for lmax) / INT_MAX (for rmin)
    // so the corresponding comparison always trivially passes (no constraint).
    //
    // Whenever a subtree turns out to be a valid BST, we update the global
    // answer 'sum' with its csum (every valid BST subtree, including leaves,
    // is a candidate).
    bool valid(TreeNode* root, int &subMin, int &subMax, int &csum, int &sum){
        // Leaf node: trivially a valid BST on its own
        if(!root->left && !root->right){
            subMin = root->val;
            subMax = root->val;
            csum = root->val;
            sum = max(sum, csum);
            return true;
        }

        bool lf = true, rf = true;
        int lmin, lmax, rmin, rmax;
        int lsum = 0, rsum = 0;

        if(root->left) lf = valid(root->left, lmin, lmax, lsum, sum);
        else { 
            lmax = INT_MIN;
            lmin = root->val; } // no left child -> no lower-bound constraint

        if(root->right) rf = valid(root->right, rmin, rmax, rsum, sum);
        else { 
            rmin = INT_MAX; 
            rmax = root->val; } // no right child -> no upper-bound constraint

        // Combine: both children must be valid BSTs, and root's value must
        // fit strictly between left subtree's max and right subtree's min
        if(lf && rf){
            if(root->val > lmax && root->val < rmin){
                csum = lsum + rsum + root->val;
                sum = max(sum, csum);
                subMin = lmin;   // true min of this subtree = left subtree's min (or root->val if no left child)
                subMax = rmax;   // true max of this subtree = right subtree's max (or root->val if no right child)
                return true;
            }
        }

        // Not a valid BST here -> subMin/subMax won't be used meaningfully by
        // parent (parent's own lf/rf will be false too), set to safe extremes
        subMin = INT_MIN;
        subMax = INT_MAX;
        return false;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        int subMin = INT_MIN, subMax = INT_MAX, csum = 0;
        valid(root, subMin, subMax, csum, sum);
        return sum;
    }
};