class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pt1 = 0 ; 
        int pt2 = 0 ; 
        
        while(pt2<nums.size()){
            if(nums[pt2]!=0){
                nums[pt1]=nums[pt2];
                pt1++;
            }
            pt2++;
        }
        for(int i = pt1; i<nums.size();i++){
            nums[i]=0;
        }
    }
};