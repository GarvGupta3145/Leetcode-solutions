class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<tuple<int,int,char,int>,
               vector<tuple<int,int,char,int>>,
               greater<tuple<int,int,char,int>>> q;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>>mcost(n,vector<int>(k+1,INT_MAX));
        mcost[0]={0};
        q.push({0,0,labels[0],1});
        while(!q.empty()){
            auto [cost,node,c,count]=q.top();
            q.pop();
            if(node==n-1)return cost;
            for(auto [nei,wt]:adj[node]){
                int nw=cost+wt;
                char l=labels[nei];
                if(c==l && count+1<=k){
                    if(cost+wt < mcost[nei][count+1]){
                        q.push({cost+wt,nei,c,count+1});
                        mcost[nei][count+1]=cost+wt;
                    }
                    
                }
                else if(c!=l){
                        if(cost+wt < mcost[nei][1]){
                            q.push({cost+wt,nei,l,1});
                            mcost[nei][1]=cost+wt;
                        }
                    }
            }
        }
        return -1;
    }
};