class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int h=citations.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(citations[mid]>=n-mid){
                h=mid-1;
            }
            else l=mid+1;
        }
        return n-l;
    }
};