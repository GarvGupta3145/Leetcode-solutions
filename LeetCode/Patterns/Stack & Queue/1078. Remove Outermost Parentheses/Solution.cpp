class Solution {
public:
//open=1   close=0
// ()
    string removeOuterParentheses(string s) {
        string str;
        int open=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                if(open>1)str.push_back(s[i]);
            }
            else if(s[i]==')'){
                open--;
                if(open>0) str.push_back(s[i]);
            }

        }
        return str;
    }
};