class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minatp = 0, maxatp = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minatp]) minatp = i;
            if (nums[i] > nums[maxatp]) maxatp = i;
        }

        int left_idx = std::min(minatp, maxatp);
        int right_idx = std::max(minatp, maxatp);

        

        return min({right_idx + 1, n - left_idx, (left_idx + 1) + (n - right_idx)});
    }
};