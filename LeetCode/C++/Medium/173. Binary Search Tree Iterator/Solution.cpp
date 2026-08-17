/**
 // Approach:
    // - Maintain a stack holding the path from root to current smallest unvisited node.
    // - Constructor: push root, then keep pushing left children till null -> stack top = smallest val.
    // - next(): pop top (this is the next in-order value).
    //           if popped node has a right child, push that right child's leftmost path onto stack
    //           (so the next smallest unvisited value ends up on top).
    // - hasNext(): stack non-empty means there are still unvisited nodes.
    // Time: next()/hasNext() -> O(1) amortized (each node pushed & popped once overall -> O(n) total over n calls)
    // Space: O(h) -> stack holds at most one path root-to-leaf at a time

 */
class BSTIterator {
private:
    stack<TreeNode*> st;
    
    void pushLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode*curr=st.top();
        st.pop();
        if(curr->right)pushLeft(curr->right);
        return curr->val;
    }
    bool hasNext() {
        if(!st.empty())return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */