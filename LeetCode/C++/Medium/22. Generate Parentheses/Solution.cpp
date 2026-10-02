class Solution {
public:
    void generate(int n, int count,int cnt, string s, vector<string> &ans) {
        if (s.size() == n * 2) {
            ans.push_back(s);
            return;
        }

        if(count<n)generate(n, count + 1,cnt ,s + '(', ans);
        if (cnt<count)
            generate(n, count,cnt+1, s + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0,0, "", ans);
        return ans;
    }
};