class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;                  // one shared string
        serializeHelper(root, s);  // built by reference, not returned+copied
        return s;
    }

    // Appends directly into s instead of returning a new string per call
    // and copying it up (old way was O(n^2) on skewed trees: deeper nodes'
    // chars got copied once per ancestor level). This is O(n).
    void serializeHelper(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val);
        s += ',';
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Preorder + bound trick (no NULL markers needed). If a value fails
    // the bound check, i is rolled back to `save` so it can be re-read
    // by another call with a looser bound — otherwise it'd be lost for good
    // (this was the earlier [2,1,3] -> [2,1] bug).
    TreeNode* build(string &preorder, int &i, int bound) {
        if (i >= preorder.size()) return NULL;

        int save = i;
        int val = 0;
        bool neg = false;
        while (preorder[i] != ',') {
            if (preorder[i] == '-') neg = true;
            else val = val * 10 + preorder[i] - '0';
            i++;
        }
        if (neg) val *= -1;

        if (val > bound) {
            i = save;   // undo the read
            return NULL;
        }
        i++;

        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, i, val);
        root->right = build(preorder, i, bound);
        return root;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i, INT_MAX);
    }
};