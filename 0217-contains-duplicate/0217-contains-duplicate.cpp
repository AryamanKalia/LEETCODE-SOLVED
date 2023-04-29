class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> abc;
        bool flag=false;
        for(auto i = nums.begin();i<nums.end();i++){
            
            if(abc.find(*i)==abc.end()){
                abc.insert(*i);
            }
            else{
                flag=true;
                break;
            }
        }
        return flag;
    }
};