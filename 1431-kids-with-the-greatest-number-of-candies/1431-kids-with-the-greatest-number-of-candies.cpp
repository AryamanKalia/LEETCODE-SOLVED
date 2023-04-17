class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> sol;int ax= candies[0];
        for(auto i =candies.begin() ; i<candies.end();i++ ){
            ax=max(*i,ax);
        }
        for(auto i = candies.begin();i<candies.end(); i++){
            if(*(i)+extraCandies>=ax){
                sol.push_back(true);
                
            }
            else 
                sol.push_back(false);
        }
        return sol;
            }
};