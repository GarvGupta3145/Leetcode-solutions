class Solution {
public:

int minMoves(vector<int>& nums) {
    int n = nums.size();
    int moves = 0;

    while (true) {
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int minVal = *min_element(nums.begin(), nums.end());

        if (nums[maxIdx] == minVal) {
            break;
        }

        for (int i = 0; i < n; i++) {
            if (i != maxIdx) {
                nums[i]++;
            }
        }
        moves++;
    }
    return moves;
}
};