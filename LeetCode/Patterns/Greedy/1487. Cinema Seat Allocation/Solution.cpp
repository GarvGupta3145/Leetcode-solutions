class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int count=0;
        unordered_map<int,vector<int>>mp;
        for(auto var:res){
            int a=var[0];
            int b=var[1];
            mp[a].push_back(b);
        }
        for(auto &[row,seats]:mp){
            vector<int>s(11,0);
            for(auto seat:seats){
                s[seat]=-1;
            }
            bool c=true;
            bool b1=true;
            if(s[2]==0 && s[3]==0 &&s[4]==0 &&s[5]==0){
                count++;
                b1=false;
            }
            if(s[4]==0 && s[5]==0 && s[6]==0 &&s[7]==0){
                c=false;
            }
            bool b2=true;
            if(s[6]==0&& s[7]==0&&s[8]==0&&s[9]==0){
                count++;
                b2=false;
            }
            if(b1 && b2 && !c)count++;
        }
        count+=(n-mp.size())*2;
        return count;
    }
};