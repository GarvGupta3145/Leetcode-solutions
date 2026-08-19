class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;                  // single shared string, built once
        serializeHelper(root, s);  // passed by reference, not returned+copied
        return s;
    }

    // Appends directly into s instead of returning a new string per call
    // and copying it up with +=. The old version created a fresh string at
    // every recursive call, so deeper nodes' characters got copied once per
    // ancestor level on the way back up — O(n^2) worst case on skewed trees,
    // even though the final string is only O(n) long. This version writes
    // each character exactly once. O(n).
    void serializeHelper(TreeNode* root, string &s) {
        if (!root) {
            s += "n,";   // explicit null marker
            return;
        }
        s += to_string(root->val);
        s += ',';
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Note: s is taken by reference (string &s). The original took it by
    // value (string s), which copies the ENTIRE string on every single
    // recursive call — O(n) extra work per call, O(n^2) total across the
    // whole recursion.
    TreeNode* solve(string &s, int &i) {
        if (i >= s.size()) return NULL;

        if (s[i] == 'n') {
            i += 2;   // skip both 'n' and the following ',' in one go.
                      // Original only did i++ here, which left i pointing
                      // at the ',' instead of past it, misaligning every
                      // subsequent read.
            return NULL;
        }

        // Original also had `if(s[i]==',')i++;` right here before checking
        // for 'n'. That's wrong: at the start of a token, i never points at
        // a leading comma (the previous token's trailing comma was already
        // consumed by the caller), so this could skip past a real digit or
        // misalign i entirely. Removed.

        int val = 0;
        bool neg = false;
        while (s[i] != ',') {
            if (s[i] == '-') neg = true;
            else val = val * 10 + s[i] - '0';
            i++;
        }
        if (neg) val *= -1;
        i++;  // skip ','

        TreeNode* root = new TreeNode(val);
        root->left = solve(s, i);
        root->right = solve(s, i);
        return root;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return solve(data, i);
    }
};