class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();
                        vector<int>dx={-1,1,0,0};
                        vector<int>dy={0,0,-1,1};
                        for(int d=0;d<4;d++){
                            int r=x+dx[d];
                            int c=y+dy[d];
                            if(r>=0 &&r<rows && c>=0 && c<cols && grid[r][c]=='1'&& !visited[r][c]){
                                q.push({r,c});
                                visited[r][c]=true;
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};