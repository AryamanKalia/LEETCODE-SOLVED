class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> abc;
        vector<int> ab(t.size());
        for(int i = t.size()-1;i>=0;i--){
            while(abc.empty()!=true && abc.top().first<=t[i]){
                abc.pop();
            }
            if(abc.empty()!=true){
                ab[i]=abc.top().second-i;
            }
            else{
                ab[i]=0;
            }
            abc.push(make_pair(t[i],i));
        }
        return ab;
    }
};