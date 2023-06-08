class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int ma= INT_MIN;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i]==1){
                j++;
                ma=max(j,ma);
            }
            else
                j=0;
            ma=max(j,ma);
        }
        return ma;
    }
};