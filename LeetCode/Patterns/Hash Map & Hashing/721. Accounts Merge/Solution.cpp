class DisjointSet{
private:
    unordered_map<string,string> parent;
    unordered_map<string,int> size;
public:
    DisjointSet(vector<vector<string>>& accounts){
        for(auto& acc : accounts){
            for(int j=1; j<acc.size(); j++){
                parent[acc[j]] = acc[j];
                size[acc[j]] = 1;
            }
        }
    }
    string findPar(string email){
        if(parent[email]==email)return email;
        return parent[email]=findPar(parent[email]);
    }

    void unionBySize(string e1,string e2){
        string p1=findPar(e1);
        string p2=findPar(e2);
        if(p1==p2)return;

        if(size[p1]<size[p2]){
            swap(p1,p2);
        }
        parent[p2]=p1;
        size[p1]+=size[p2];
    }

    bool find(string e1,string e2){
        return findPar(e1)==findPar(e2);
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts);

        unordered_map<string,string> emailToName;
        for(auto& acc : accounts){
            for(int j=1; j<acc.size(); j++){
                emailToName[acc[j]] = acc[0];
            }
        }

        for(int i=0;i<accounts.size();i++){
            for(int j=2;j<accounts[i].size();j++){
                if(ds.find(accounts[i][j],accounts[i][1]))continue;
                else{
                    ds.unionBySize(accounts[i][j],accounts[i][1]);
                }
            }
        }

        unordered_map<string, vector<string>> groups;
        for(auto& [email, name] : emailToName){
            groups[ds.findPar(email)].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto& [root, emails] : groups){
            sort(emails.begin(), emails.end());
            vector<string> row = {emailToName[root]};
            row.insert(row.end(), emails.begin(), emails.end());
            ans.push_back(row);
        }
        return ans;
    }
};