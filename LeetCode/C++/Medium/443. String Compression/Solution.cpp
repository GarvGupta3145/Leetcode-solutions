class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, write = 0;

        while (i < n) {
            char ch = chars[i];
            int cnt = 0;

            while (i < n && chars[i] == ch) {
                cnt++;
                i++;
            }

            chars[write++] = ch;

            if (cnt > 1) {
                string freq = to_string(cnt);

                for (char c : freq) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};