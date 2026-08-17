class Solution {
public:
    void pushLeft(stack<TreeNode*>& st, TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }

    void pushRight(stack<TreeNode*>& st, TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> lo, hi;
        pushLeft(lo, root);
        pushRight(hi, root);

        while(lo.top() != hi.top()) {
            int sum = lo.top()->val + hi.top()->val;
            if(sum == k) return true;
            else if(sum < k) {
                TreeNode* curr = lo.top();
                lo.pop();
                if(curr->right) pushLeft(lo, curr->right);
            } else {
                TreeNode* curr = hi.top();
                hi.pop();
                if(curr->left) pushRight(hi, curr->left);
            }
        }
        return false;
    }
};