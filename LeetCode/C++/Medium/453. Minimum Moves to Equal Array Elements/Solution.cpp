class Solution {
public:
    long long minMoves(vector<int>& nums) {
    vector<long long> a(nums.begin(), nums.end());
    long long moves = 0;

    while (true) {
        long long mx = *max_element(a.begin(), a.end());
        long long secondMax = LLONG_MIN;
        int cnt = 0;

        for (long long x : a) {
            if (x == mx) {
                cnt++;
            } else {
                secondMax = max(secondMax, x);
            }
        }

        if (secondMax == LLONG_MIN) {
            break;
        }

        long long diff = mx - secondMax;
        moves += diff * cnt;

        for (long long& x : a) {
            if (x == mx) {
                x = secondMax;
            }
        }
    }
    return moves;
}
};