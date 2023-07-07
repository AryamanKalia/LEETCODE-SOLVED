class Solution {
public:
    vector<vector<int>> abcd;
    void perm(vector<int>& nums , vector<int> nu,vector<int> abc , int count){
        if(count == nums.size()){
            abcd.push_back(abc);
            return ;
    }
    for(int i = 0 ; i<nu.size();i++){
        if(nu[i]==-1){
            abc.push_back(nums[i]);
            nu[i]=1;
            perm(nums,nu,abc,count+1);
            nu[i]=-1;
            abc.pop_back();
        }
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<int>nuu(nums.size(),-1);
     vector<int> abcc;
        perm(nums,nuu,abcc,0);
        return abcd;
    }
};