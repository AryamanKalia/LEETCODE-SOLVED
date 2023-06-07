class Solution {
public:
    static void reverse(vector<int>& nums, int k,int beg ,int en){
        while(beg<=en){
            swap(nums[beg],nums[en]);
            beg++;
            en--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums,k,0,nums.size()-(k%nums.size())-1);
        reverse(nums,k,nums.size()-(k%nums.size()),nums.size()-1);
        reverse(nums,k,0,nums.size()-1);
    }
};