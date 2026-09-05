class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

    
        vector<int> prefmax(n);
        prefmax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefmax[i] = max(prefmax[i - 1], nums[i]);
        }

    
        vector<int> suffmin(n);
        suffmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffmin[i] = min(suffmin[i + 1], nums[i]);
        }

    
        for (int i = 0; i < n; i++) {
            if ( prefmax[i] - suffmin[i]<=k){
            return i; 
        }
    }

    return -1;
    }
};