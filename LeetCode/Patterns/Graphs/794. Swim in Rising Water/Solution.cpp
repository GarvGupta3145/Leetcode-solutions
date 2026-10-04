class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        pq.push({grid[0][0],0,0});

        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        while(!pq.empty()){
            auto [t,i,j]=pq.top();
            pq.pop();
            if(t>dist[i][j])continue;
            if(i==n-1 && j==n-1)return t;
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    if(grid[nx][ny]<=t && t<dist[nx][ny]){
                        pq.push({t,nx,ny});
                        dist[nx][ny]=t;
                    }
                    else if(grid[nx][ny]>t && dist[nx][ny]==INT_MAX){
                        pq.push({grid[nx][ny],nx,ny});
                        dist[nx][ny]=grid[nx][ny];
                    }
                }
            }

        }
        return -1;
    }
};