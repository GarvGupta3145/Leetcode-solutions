class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_ele = *min_element(nums.begin(), nums.end());

        int result = 0;
        for (int x : nums) {
            result += x - min_ele;
        }

        return result;
    }
};