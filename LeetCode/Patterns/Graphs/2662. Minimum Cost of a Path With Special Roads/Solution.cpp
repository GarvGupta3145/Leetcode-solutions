class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sr) {
        int tx=target[0];
        int ty=target[1];

        map<pair<int,int>, int> mincost;
        map<pair<int,int>, vector<pair<pair<int,int>, int>>> roads;

        for(int i=0;i<sr.size();i++){
            int x1=sr[i][0];
            int y1=sr[i][1];
            int x2=sr[i][2];
            int y2=sr[i][3];
            int cost=sr[i][4];
            roads[{x1,y1}].push_back({{x2, y2}, cost});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        //pq->[cost,x,y]->total cost to reach x,y
        mincost[{start[0], start[1]}] = 0;
        mincost[{tx, ty}] = abs(tx - start[0]) + abs(ty - start[1]);
        pq.push({0,start[0],start[1]});
        
        while(!pq.empty()){
            auto [cost,x,y]=pq.top();
            pq.pop();
            if(cost >mincost[{x,y}])continue;
            if(x==tx && y==ty)return cost;

            if(roads.find({x,y})!=roads.end()){
                for (auto& [end, c] : roads[{x, y}]) {
                    auto [x2, y2] = end;
                    auto it = mincost.find({x2,y2});
                    if(it==mincost.end() || cost+c < it->second){
                        mincost[{x2,y2}] = cost+c;
                        pq.push({cost+c,x2,y2});
                    }
                }
            }
            
            for (auto& [p, list] : roads) {
                int nc = cost + abs(x - p.first) + abs(y - p.second);
                auto it = mincost.find(p);
                if (it == mincost.end() || nc < it->second) {
                    mincost[p] = nc;
                    pq.push({nc, p.first, p.second});
                }
            }

            if(cost+abs(x-tx)+abs(y-ty)<mincost[{tx,ty}]){
                mincost[{tx,ty}]=cost+abs(x-tx)+abs(y-ty);
                pq.push({cost+abs(x-tx)+abs(y-ty),tx,ty});
            }


        }
        return mincost[{tx,ty}];
    }
};