class Solution {
public:
    long long minMoves(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    long long moves = 0;
    for (int i = n - 1; i > 0; i--) {
        long long diff = (long long)nums[i] - nums[i - 1];
        long long cnt = n - i;
        moves += diff * cnt;
    }
    return moves;
}
};