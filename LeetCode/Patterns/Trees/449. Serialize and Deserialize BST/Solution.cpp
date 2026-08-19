class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    void serializeHelper(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val);
        s += ',';
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

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
            i = save;
            return NULL;
        }
        i++;

        TreeNode* root = new TreeNode(val);
        root->left = build(preorder, i, val);
        root->right = build(preorder, i, bound);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i, INT_MAX);
    }
};