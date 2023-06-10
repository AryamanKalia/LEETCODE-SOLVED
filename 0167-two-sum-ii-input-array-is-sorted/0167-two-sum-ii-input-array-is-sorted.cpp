class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int left , right;
        left =0; 
        right=n.size()-1;
        vector<int>ans;
        while(left<right){
        if(n[left]+n[right]==target){
            ans.push_back(left+1);
            ans.push_back(right+1);
            return ans;
        }
        else if(n[left]+n[right]<target){
            left++;
        }
            else{
                right--;
            }
        }
        return ans;
    }
};