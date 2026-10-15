class DisjointSet {
    vector<int> parent,rank,size;
  public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    
    int findUPar(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUPar(parent[u]);
    }
    
    void unionBySize(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        
        if(pu==pv) return;
        
        if(size[pu] < size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DisjointSet ds(2 * n);

        for(auto it: dislikes){
            int u=it[0];
            int v=it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                return false;
            }

            ds.unionBySize(u, v + n);
            ds.unionBySize(v, u + n);
                   
        }
        return true;
    }
};