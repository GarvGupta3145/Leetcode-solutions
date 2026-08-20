class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected ,vector<int>&visited){
        if(!visited[node]){
            visited[node]=1;
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[node][j]==1)dfs(j,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n+1,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,isConnected,visited);
            }
        }
        return provinces;
    }
};