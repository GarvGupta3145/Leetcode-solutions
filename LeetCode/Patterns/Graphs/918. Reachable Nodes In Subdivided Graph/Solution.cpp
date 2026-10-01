class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int cnt=edges[i][2];
            adj[u].push_back({v,cnt+1});
            adj[v].push_back({u,cnt+1});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int>mn(n,INT_MAX);
        mn[0]=0;
        pq.push({0,0});
        //pq->max-budget,node

        while(!pq.empty()){
            auto [step,u]=pq.top();
            pq.pop();
            if(step > mn[u])continue;
            for(auto [v,w]:adj[u]){
                if(step+w < mn[v] && step+w <= maxMoves){
                    mn[v]=step+w;
                    pq.push({step+w,v});
                }
            }
        }
        
        int ans=0;

        for (int i = 0; i < n; i++){
            if (mn[i] <= maxMoves) ans++;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],e=edges[i][2];
            int a;
            int b;
            if(maxMoves-mn[u]>0)a=maxMoves-mn[u];
            else a=0;
            if(maxMoves-mn[v]>0)b=maxMoves-mn[v];
            else b=0;
            ans+=min(e,a+b);
        }
        return ans;
    }
};