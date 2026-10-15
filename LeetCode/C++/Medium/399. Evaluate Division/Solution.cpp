class DSU {
    
public:
    vector<int> parent;
    vector<double> wt;   // wt[x] = root / x
    DSU(int n) {
        parent.resize(n);
        wt.assign(n, 1.0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int a) {
        if (a == parent[a]) return a;
        int p = parent[a];
        parent[a] = findPar(p);
        wt[a] = wt[a] * wt[p];
        return parent[a];
    }

    void Union(int a, int b, double val) {   
        int r1 = findPar(a);
        int r2 = findPar(b);
        if (r1 == r2) return;
        parent[r2] = r1;
        wt[r2] = wt[a] * val / wt[b];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU(26);
        unordered_map<string, int> id;
        for (auto& e : equations) {
            for (auto& s : e) {
                if (!id.count(s)) {
                    int k = id.size();
                    id[s] = k;
                }
            }
        }

        DSU ds(id.size());
        for (int i = 0; i < equations.size(); i++) {
            double val = values[i];
            ds.Union(id[equations[i][0]], id[equations[i][1]], val);
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string x = queries[i][0], y = queries[i][1];

            if (!id.count(x) || !id.count(y)) {
                ans.push_back(-1.0);
                continue;
            }

            int a = id[x], b = id[y];
            if (ds.findPar(a) != ds.findPar(b)) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(ds.wt[b] / ds.wt[a]);
            }
        }
        return ans;
    }
};