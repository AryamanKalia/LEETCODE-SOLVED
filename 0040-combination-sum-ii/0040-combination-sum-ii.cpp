class Solution {
public:
    vector<vector<int>> finale;
void combination(vector<int>& candidates, int target, int sum, vector<int> candi, int l) {
    if (sum == target) {
        finale.push_back(candi);
        return;
    }
    
    for (int i = l; i < candidates.size(); i++) {
        if (i > l && candidates[i] == candidates[i - 1]) {
            continue;
        }
        if(sum+candidates[i]>target){
            break;
        }
        sum += candidates[i];
        candi.push_back(candidates[i]);
        combination(candidates, target, sum, candi, i + 1);
        candi.pop_back();
        sum -= candidates[i];
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>abc;
        combination(candidates,target,0,abc,0);
        return finale;
    }
};