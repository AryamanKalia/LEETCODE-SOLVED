class Solution {
public:
    vector<vector<int>> finale;
     void combination(vector<int>& candidates, int target,vector<int> candi , int l){
        if(target <0){
            return ;
        }
        else if(target==0){
           finale.push_back(candi); 
            return;
        }
        for(int i = l; i<candidates.size();i++){
            candi.push_back(candidates[i]);
            combination(candidates,target - candidates[i] , candi , i);
            candi.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> abc;
        combination(candidates,target,abc,0);
        return finale;
    }
};