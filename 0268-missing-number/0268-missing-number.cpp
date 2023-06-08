class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>h;
        for(int i = 0 ; i < nums.size();i++){
            h.insert(nums[i]);
        }
        int i = 0 ; 
        for( i = 0 ; i < nums.size(); i++){
            if(h.find(i)==h.end())
                return i;
        }
        return i ; 
    }
};