class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
        queue<pair<int,int>>q;
        q.push({0, 0});
        int n=grid.size();
        int row=0;
        int col=0;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=0;
        if(grid[0][0]==1)return -1;
        while(!q.empty() ){
            auto [r,c]=q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol]==0 
                && dist[nrow][ncol] > dist[r][c]+1){

                    dist[nrow][ncol] = dist[r][c] + 1;
                    q.push({nrow, ncol});
                    
                }
             }
            
        }
        return dist[n-1][n-1]==1e9?-1 :dist[n-1][n-1]+1;
    }
};