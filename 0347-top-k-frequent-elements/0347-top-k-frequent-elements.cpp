class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>abc;
        for(int i = 0 ; i<nums.size();i++){
            abc[nums[i]]++;
        }
        vector<int>abcd;
        for(int i = 0 ; i<k;i++){
        int maxi=INT_MIN;
        int el=INT_MIN;
        for(auto ii = abc.begin();ii!=abc.end();ii++){
            if(ii->second>maxi){
                maxi=ii->second;
                el=ii->first;
            }
        }
        abcd.push_back(el); 
        abc.erase(el);
    }
        return abcd ;
    }
};