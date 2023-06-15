
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>abc;
        for(int i = 0 ; i<nums1.size();i++){
            abc[nums1[i]]=i;
        }
        stack<int> abcd;
        for(int i = nums2.size()-1;i>=0;i--){
            if(abc.find(nums2[i])!=abc.end()){
                while((abcd.empty()!=true && abcd.top()<=nums2[i])){
                        abcd.pop();
                    }
                if(abcd.empty()==true){
                   nums1[abc[nums2[i]]]=-1;
                }
                else{
                    nums1[abc[nums2[i]]]=abcd.top();
                }
                }
            abcd.push(nums2[i]);
            }
        return nums1;
        }
        
};