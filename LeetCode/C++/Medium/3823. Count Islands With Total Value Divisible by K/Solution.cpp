class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        int ans=0;
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && visited[i][j]==-1){
                    long long sum=0;
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        sum+=grid[x][y];
                        q.pop();
                        for(int d=0;d<4;d++){
                            int nx=x+dx[d];
                            int ny=y+dy[d];
                            if(nx<0 || nx==n || ny<0 ||ny==m )continue;
                            else if(grid[nx][ny]>0 && visited[nx][ny]==-1){
                                q.push({nx,ny});
                                visited[nx][ny]=1;
                            }
                        }
                    }
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};