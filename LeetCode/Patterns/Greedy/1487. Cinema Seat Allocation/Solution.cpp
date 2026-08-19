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
            if(s[2]==-1 ||s[3]==-1 ||s[4]==-1 ||s[5]==-1){
                if(s[4]==-1 || s[5]==-1)b1=false;
                c=false;
            }
            else count++;
            bool b2=true;
            if(s[6]==-1|| s[7]==-1 ||s[8]==-1 ||s[9]==-1){
                if(s[6]==-1 || s[7]==-1)b2=false;
                c=false;
            }
            else count++;
            if(c)count++;
        }
        count+=(n-mp.size())*2;
        return count;
    }
};