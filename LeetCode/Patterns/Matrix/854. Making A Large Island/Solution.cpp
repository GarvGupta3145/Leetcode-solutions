class DisjointSet{
private:
    vector<int>parent,size;
public:
    DisjointSet(int n){
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i=0;i<n*n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int id){
        if(parent[id]==id)return id;
        return parent[id]=findUPar(parent[id]);
    }

    void unionBySize(int id1,int id2){
        int root1=findUPar(id1);
        int root2=findUPar(id2);
        if(root1==root2)return;

        if(size[root1]<size[root2]){
            swap(root1,root2);
        }
        parent[root2]=root1;
        size[root1]+=size[root2];
    }

    bool find(int id1,int id2){
        return findUPar(id1)==findUPar(id2);
    }
    int findSize(int id){
        return size[findUPar(id)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n);
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int id=i*n+j;
                if(grid[i][j]==1){
                    for(int d=0;d<4;d++){
                        int nx=i+dx[d];
                        int ny=j+dy[d];
                        if(nx>=0 && ny>=0 && nx<n && ny<n){
                            if(grid[nx][ny]==1){
                                int nid=nx*n+ny;
                                if(!ds.find(nid,id)){
                                    ds.unionBySize(nid,id);
                                }
                            }
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int id=i*n+j;
                mx=max(mx,ds.findSize(id));
                if(grid[i][j]==0){
                    int curr=1;
                    vector<int>par;
                    for(int d=0;d<4;d++){
                        int nx=i+dx[d];
                        int ny=j+dy[d];
                        int nid=nx*n+ny;
                        if(nx>=0 && ny>=0 && nx<n && ny<n){
                            if(grid[nx][ny]==1){
                                bool found=false;
                                for(int p:par){
                                    if(ds.find(nid,p)){ found=true; break; }
                                }
                                if(!found){
                                    par.push_back(nid);
                                    curr+=ds.findSize(nid);
                                }
                            }
                            mx=max(mx,curr);
                        }
                    }
                }
            }
        }
        return mx;
    }
};