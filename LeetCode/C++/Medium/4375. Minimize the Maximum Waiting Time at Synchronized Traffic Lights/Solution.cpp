class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int m=INT_MIN;
        for(int i=0;i<lights.size();i++){
            m=max(m,lights[i]);
        };
        int pena=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r=arrivalTime[i]%period;
            if(r>=m)pena=max(pena,period-r);
        }
        return pena;
    }
};