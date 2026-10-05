class DisjointSet {
private:
    vector<int> parent;
    vector<int> componentSize;
 
public:
    DisjointSet(int n) {
        parent.resize(n);
        componentSize.assign(n,1);
        for (int node = 0; node < n; node++) {
            parent[node] = node;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) {
            return;
        }
        if (componentSize[rootU] < componentSize[rootV]) {
            swap(rootU, rootV);
        }
        parent[rootV] = rootU;
        componentSize[rootU] += componentSize[rootV];
    }

    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }
    
    int componentSizeOf(int node) {
        return componentSize[findParent(node)];
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int redundant=0;
        int component=n;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(ds.find(u,v))redundant++;
            else{
                ds.unionBySize(u,v);
                component--;
            }
        }
        if(redundant>=component-1)return component-1;
        return -1;
    }
};