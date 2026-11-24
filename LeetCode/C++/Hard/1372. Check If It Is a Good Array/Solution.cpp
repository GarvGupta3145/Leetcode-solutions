class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (int x : nums) g = __gcd(g, x);
        return g == 1;
    }
};