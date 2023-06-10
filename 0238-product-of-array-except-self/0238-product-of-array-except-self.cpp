class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product= 1;
        unordered_set<int>abc;
        int ii = 0 ; 
        for(auto i = nums.begin();i!=nums.end();i++){
            if(*i==0){
                product=product*1;
                abc.insert(ii);
            }
            else{
                product=product*(*i);
            }
            ii++;
        }
        vector<int>abcd;
        for(int iii = 0; iii<nums.size();iii++){
            if(nums[iii]==0){
                abc.erase(iii);
                if(abc.size()!=0){
                    abcd.push_back(0);
                }
                else{
                    abcd.push_back(product);
                }
                abc.insert(iii);
            }
            else{
                if(abc.size()!=0){
                    abcd.push_back(0);
                }
                else{
                    abcd.push_back(product/nums[iii]);
                }
            }
        }
        return abcd;
    }
};