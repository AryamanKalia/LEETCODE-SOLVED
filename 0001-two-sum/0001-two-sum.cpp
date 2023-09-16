class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prev;
        vector<int> aa;
        int ii = 0 ;
        for(auto i : nums){
            if(prev.find((target-i))==prev.end()){
                prev[i]=ii;
                ii++;
                continue;
            }
            aa.push_back(prev[(target-i)]);
            aa.push_back(ii);
            return aa;
        }
        return aa;
    }
};