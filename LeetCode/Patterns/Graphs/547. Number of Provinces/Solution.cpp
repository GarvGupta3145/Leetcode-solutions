class DisjointSet{
private:
    vector<int>parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) {
            return;
        }
        if (size[rootU] < size[rootV]) {
            swap(rootU, rootV);
        }
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }

    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }
    
    int componentSizeOf(int node) {
        return size[findParent(node)];
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        int provinces=n;
        for (int i = 0; i <n; i++) {
            for (int j = i + 1; j <n; j++) {
                if (isConnected[i][j] == 1) {
                    if (ds.find(i, j))continue;
                    else {
                        ds.unionBySize(i, j);
                        provinces--;
                    }
                }
            }
        }
        return provinces;

        
    }
};