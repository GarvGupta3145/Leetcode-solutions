class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();int n=board[0].size();
        vector<vector<bool>>check(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                check[0][i]=true;
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                check[m-1][i]=true;
                q.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                check[i][0]=true;
                q.push({i,0});
            }
            if(board[i][n-1]=='O'){
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
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny]=='O' && 
                    check[nx][ny] == false) {
                    check[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && check[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }
};