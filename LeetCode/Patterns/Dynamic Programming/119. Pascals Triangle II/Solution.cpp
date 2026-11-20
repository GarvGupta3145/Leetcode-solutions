class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        long ans=1;
        for(int i=0;i<rowIndex;i++){
            ans=ans*(rowIndex-i);
            ans/=(i+1);
            row.push_back(ans);
        }
        return row;
    }
};