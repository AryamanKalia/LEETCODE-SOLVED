class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0 ;
        for(int j = 0 ; j<nums.size();j++){
            i = i^nums[j];
        }
        return i ; 
    }
};