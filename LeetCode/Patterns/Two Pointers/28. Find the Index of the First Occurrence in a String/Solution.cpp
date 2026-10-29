class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        if(pos!=-1)return pos;
        return -1;
    }
};