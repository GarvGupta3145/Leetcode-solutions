class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int time=edges[i][2];
            adj[u].push_back({time,v});
            adj[v].push_back({time,u});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int>time(n,INT_MAX);
        pq.push({0,0});
        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();
            if(t>=time[node])continue;
            time[node]=t;
            for(auto [tn,nei]:adj[node]){
                if(tn+t>time[nei] || tn+t >=disappear[nei])continue;
                pq.push({tn+t,nei});
            }
        }
        for(int i=0;i<n;i++){
            if(time[i]==INT_MAX)time[i]=-1;
        }
        return time;


    }
};