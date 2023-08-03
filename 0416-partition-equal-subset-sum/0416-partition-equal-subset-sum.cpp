class Solution {
public:
    bool subsetsum(vector<int>& nums,int n, int sum,vector<vector<int>>& t){
        if(sum==0)return true;
        if(n<=0){
            if(sum==0)return true;
            else return false;
        }
        if(t[n][sum]!=-1)return t[n][sum];
        if(sum>=nums[n-1]){
            return t[n][sum]=subsetsum(nums,n-1,sum-nums[n-1],t) || subsetsum(nums,n-1,sum,t);
        }
        return t[n][sum]=subsetsum(nums,n-1,sum,t);
    }
    bool canPartition(vector<int>& nums) {
        int sums = 0;
        for(int i = 0 ; i<nums.size();i++){
            sums+=nums[i];
        }
        if(sums%2==1)return false;
        vector<vector<int>> t(nums.size()+1,vector<int>((sums/2)+1,-1));
        return subsetsum(nums,nums.size(),sums/2,t);
    }
};