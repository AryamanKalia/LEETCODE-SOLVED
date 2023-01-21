class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int count=1;
    int nu=nums[0];
    for(int i =1;i<nums.size();i++){
        if(nums[i]!=nu){
            nums[count]=nums[i];
            nu=nums[i];
            count++;
        }
    }return count;
        
    }
};