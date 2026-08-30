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

        // Option 1: Delete both from the left front
        int op1 = right_idx + 1;
        
        // Option 2: Delete both from the right back
        int op2 = n - left_idx;
        
        // Option 3: Delete smaller from left, larger from right
        int op3 = (left_idx + 1) + (n - right_idx);

        return std::min({op1, op2, op3});
    }
};