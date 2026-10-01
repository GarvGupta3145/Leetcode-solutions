class Solution {
public:
    bool check(stack<char>& st, char s) {
        if (!st.empty()) {
            if (st.top() == '(' && s == ')')
                return true;
            if (st.top() == '{' && s == '}')
                return true;
            if (st.top() == '[' && s == ']')
                return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (check(st, s[i]) == false)
                    return false;
                st.pop();
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};