class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        vector<int> ans(n);
        vector<int> temp; // sorted (increasing), holds unused sorted_nums elements
        int j = 0;

        for (int i = 0; i < n; i++) {
            // search temp for smallest element within limit of nums[i]
            int lo = 0, hi = (int)temp.size() - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (abs(temp[mid] - nums[i]) <= limit) {
                    pos = mid;
                    hi = mid - 1; // look for smaller/earlier fit
                } else if (temp[mid] < nums[i] - limit) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (pos != -1) {
                ans[i] = temp[pos];
                temp.erase(temp.begin() + pos);
                continue;
            }

            // pull from sorted_nums until one fits, stashing mismatches in temp
            while (j < n && abs(sorted_nums[j] - nums[i]) > limit) {
                temp.push_back(sorted_nums[j]);
                j++;
            }
            ans[i] = sorted_nums[j];
            j++;
        }

        return ans;
    }
};