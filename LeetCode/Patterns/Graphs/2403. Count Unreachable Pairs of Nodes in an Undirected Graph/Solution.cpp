class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,false);
        long long pairs=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int v=0;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    v++;
                    for(auto nei:adj[node]){
                        if(!visited[nei]){
                            visited[nei]=true;
                            q.push(nei);
                        }
                    }
                }
                pairs+=(n-v)*v;
            }
        }
        return pairs/2;
    }
};