class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            if(matrix[0][i]=='1')dp[i]=1;
        }
        int ans=0;
        for(int i=1;i<m;i++){
            int diag=0;
            for(int j=0;j<n;j++){
                int lu=dp[j];
                int left=j==0?0:dp[j-1];
                if(matrix[i][j]=='0'){
                    dp[j]=0;
                }
                if(matrix[i][j]=='1'){
                    int curr=1+min(diag,min(left,dp[j]));
                    ans=max(ans,curr);
                    dp[j]=curr;
                }
                diag=lu;
            }
        }
        return ans*ans;
    }
};