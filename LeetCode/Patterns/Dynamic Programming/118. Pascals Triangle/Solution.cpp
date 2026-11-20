class Solution {
public:
vector<int>rows(int n){
    vector<int> row;
    row.push_back(1);
    long ans=1;
    for(int i=0;i<n;i++){
        ans=ans*(n-i);
        ans/=(i+1);
        row.push_back(ans);
    }
    return row;
}
vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans;
    for(int i=0;i<numRows;i++){
        ans.push_back(rows(i));
    }
    return ans;  
    }
};