class Solution {
public:
    // In-order traversal of a valid BST is strictly increasing.
    // Walk the tree in-order, keeping track of the previously visited node.
    // Whenever prev->val > root->val, we've found a "violation" point.
    // - If the two swapped nodes are adjacent in in-order sequence,
    //   exactly ONE violation occurs, involving both swapped nodes (prev and root).
    // - If they are NOT adjacent, TWO violations occur:
    //   the first violation's "prev" and the second violation's "root"
    //   are the actual swapped nodes (the middle elements get flagged
    //   as root/prev respectively but aren't the true culprits).
    void inorder(TreeNode* root, vector<TreeNode*>& temp, TreeNode*& prev) {
        if (!root) return;

        inorder(root->left, temp, prev);

        // Check current node against previously visited node (in-order predecessor)
        if (prev && prev->val > root->val) {
            if (temp.empty()) {
                // First violation: record the earlier node (prev) as first culprit
                temp.push_back(prev);
            }
            // Always record the later node of a violation as (potential) second culprit
            temp.push_back(root);
        }
        prev = root;

        inorder(root->right, temp, prev);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> temp;
        TreeNode* prev = nullptr;
        inorder(root, temp, prev);

        // temp.size() == 2 -> single violation -> swapped nodes are adjacent in in-order
        // temp.size() == 3 -> two violations -> swapped nodes are temp[0] and temp[2]
        //                      (temp[1] is caught twice but isn't a true culprit)
        if (temp.size() == 2) {
            swap(temp[0]->val, temp[1]->val);
        } else if (temp.size() == 3) {
            swap(temp[0]->val, temp[2]->val);
        }
    }
};