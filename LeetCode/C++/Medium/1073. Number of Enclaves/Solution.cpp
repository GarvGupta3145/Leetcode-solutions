class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<bool>>check(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                check[0][i]=true;
                q.push({0,i});
            }
            if(grid[m-1][i]==1){
                check[m-1][i]=true;
                q.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                check[i][0]=true;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                check[i][n-1]=true;
                q.push({i,n-1});
            }
        }

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny]==1 && 
                    check[nx][ny] == false) {
                    check[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && check[i][j]==false){
                    count++;
                }
            }
        }
        return count;
    }
};