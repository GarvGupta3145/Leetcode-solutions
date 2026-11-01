class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>up(n,0);
        up[0]=grid[0][0];
        for(int i=1;i<n;i++){
            up[i]=up[i-1]+grid[0][i];
        }

        for(int i=1;i<m;i++){
            int prev=0;
            for(int j=0;j<n;j++){
                int old=up[j];
                if(j==0){
                    up[j]+=grid[i][j];
                }
                else{
                    up[j]=min(up[j],up[j-1])+grid[i][j];
                }
                prev=old;
            }
        }
        return up[n-1];
    }
};