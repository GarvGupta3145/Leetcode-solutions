class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>mn(n,vector<int>(m,INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0,0,0});
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!pq.empty()){
            auto [time,i,j]=pq.top();
            pq.pop();
            if(mn[i][j]<time)continue;
            mn[i][j]=time;
            if(i==n-1 && j==m-1)return time;
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];
                if(nx>=0 && ny>=0 && nx<n && ny<m && time+1<mn[nx][ny]){
                    if(moveTime[nx][ny]<=time)pq.push({time+1,nx,ny});
                    else pq.push({moveTime[nx][ny]+1,nx,ny});
                }
            }

        }
        return -1;
    }
};