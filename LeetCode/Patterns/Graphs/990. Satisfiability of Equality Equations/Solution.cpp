class DisjointSet {
public:
    vector<int> par;

    DisjointSet(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int findPar(int x) {
        if (par[x] != x) par[x] = findPar(par[x]);
        return par[x];
    }

    void Union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if (a < b) par[b] = a;
        else par[a] = b;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);

        for (auto& e : equations)
            if (e[1] == '=')
                ds.Union(e[0] - 'a', e[3] - 'a');

        for (auto& e : equations)
            if (e[1] == '!' && ds.findPar(e[0] - 'a') == ds.findPar(e[3] - 'a'))
                return false;

        return true;
    }
};