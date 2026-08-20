class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int st=image[sr][sc];
        queue<pair<int,int>>q;
        if(st==color)return image;
        q.push({sr,sc});
        int m=image.size();
        int n=image[0].size();
        image[sr][sc]=color;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                int l=col-1,r=col+1,t=row-1,b=row+1;
                if(t>=0 && image[t][col]==st){
                    image[t][col]=color;
                    q.push({t,col});
                }
                if(l>=0 && image[row][l]==st){
                    image[row][l]=color;
                    q.push({row,l});
                }

                if(b<m && image[b][col]==st){
                    image[b][col]=color;
                    q.push({b,col});
                }
                if(r<n && image[row][r]==st){
                    image[row][r]=color;
                    q.push({row,b});
                }
            }
            
        }
        return image;
    }
};