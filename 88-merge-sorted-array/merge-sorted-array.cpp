class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i = 0 , j = 0;
        while(i<m&&j<n){
            if (nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
            }
        
        }
        if (j<n){
            for(int s = j;s<n;s++){
                ans.push_back(nums2[s]);}}
        if (i<m){for(int s = i;s<m;s++){ans.push_back(nums1[s]);}}
        nums1 = ans;
    }
};