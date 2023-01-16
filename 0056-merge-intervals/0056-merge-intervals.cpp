bool koro(vector<int> a , vector<int> b){
         return a[0]<b[0];  }
class Solution {
public:
    
  
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort function call 
        // ac cording to starting time in ascending order
        sort(intervals.begin(),intervals.end(),koro);
        vector<vector<int>> addd;
        addd.push_back(intervals[0]);
        for(int i = 1; i<intervals.size();i++){
            if(addd.back()[1]>=intervals[i][0]){
                if(addd.back()[1]<intervals[i][1]){
                    addd.back()[1]=intervals[i][1];
                }

            }
            else
            addd.push_back(intervals[i]);

            
        }
        return  addd;

    }
};