class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        vector<int> memo(n, -1); // Memoization table to store computed LIS lengths
        
        int maxLIS = 1;
        for (int i = 0; i < n; ++i) {
            maxLIS = max(maxLIS, findLIS(nums, i, memo));
        }
        
        return maxLIS;
    }
    
    int findLIS(vector<int>& nums, int index, vector<int>& memo) {
        if (memo[index] != -1)
            return memo[index];
        
        int maxLength = 1; // Minimum length is 1 (the number itself)
        for (int i = 0; i < index; ++i) {
            if (nums[index] > nums[i]) {
                maxLength = max(maxLength, 1 + findLIS(nums, i, memo));
            }
        }
        
        memo[index] = maxLength;
        return maxLength;
    }
};
