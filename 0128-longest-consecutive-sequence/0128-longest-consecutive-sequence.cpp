class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>a;
        for(auto i = nums.begin();i!=nums.end();i++){
            a.insert(*i);
        }
        int ma=0;
        for(auto i = nums.begin();i!=nums.end();i++){
         if(a.find(*i)!=a.end() && a.find(*i-1)==a.end()){
             int aa=*i;
             int count=0;
             while(a.find(aa)!=a.end()){
                 a.erase(aa);
                aa++;
                 count++;
             }
             ma=max(count,ma);
         }   
        }
        return ma;
    }
};