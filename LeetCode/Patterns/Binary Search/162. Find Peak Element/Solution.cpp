class Solution {
public:
    int bin(vector<int>& nums, int low, int high) {
        // Base case: when only one element remains
        if (low == high) 
            return low;

        int mid = low + (high - low) / 2;

        // If mid element is greater than next, peak lies on the left (including mid)
        if (nums[mid] > nums[mid + 1])
            return bin(nums, low, mid);
        else
            return bin(nums, mid + 1, high);
    }

    int findPeakElement(vector<int>& nums) {
        return bin(nums, 0, nums.size() - 1);
    }
};
