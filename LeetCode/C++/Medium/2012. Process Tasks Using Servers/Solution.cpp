class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // (weight, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeServers;
        // (freeTime, weight, index)
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> busy;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long t = 0;

        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);

            while (!busy.empty() && get<0>(busy.top()) <= t) {
                auto [ft, w, idx] = busy.top();
                busy.pop();
                freeServers.push({w, idx});
            }

            if (freeServers.empty()) {
                t = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= t) {
                    auto [ft, w, idx] = busy.top();
                    busy.pop();
                    freeServers.push({w, idx});
                }
            }

            auto [w, idx] = freeServers.top();
            freeServers.pop();
            ans[j] = idx;
            busy.push({t + tasks[j], w, idx});
        }

        return ans;
    }
};