class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int r=0;
        int c=0;
        int i=0;
        int j=0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
        while(i<grid.size() && j< grid[0].size() && visited[i][j]==-1){
            char a=grid[i][j];
            r=i;
            c=j;
            visited[i][j]=1;
            if(a=='U'){
                i--;
                continue;
            }
            if(a=='D'){
                i++;
                continue;
            }
            if(a=='L'){
                j--;
                continue;
            }
            else j++;
        }
        return {r,c};

    }
};