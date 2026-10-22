class Solution {
public:
    int hIndex(vector<int>& citations) {
          sort(citations.begin(),citations.end());
          int c=1;
          for(int i=citations.size()-1;i>=0;i--){
            if(c>citations[i]){
                break;
            }
            c++;
          }
          return c-1;

    }
};