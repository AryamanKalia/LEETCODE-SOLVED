class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> AtoZ(heights.size());vector<pair<int,int>> ZtoA(heights.size());

        stack<pair<int,int>> prev;
        int ii = 0  ;
        for(auto i : heights){
            
            while(prev.empty()!=true && prev.top().second>= i){
                prev.pop();
            }
            if(prev.empty()==true){
                AtoZ[ii]=make_pair(-1,-1);
            }
            else{
                AtoZ[ii]=prev.top();
            }
            prev.push(make_pair(ii,i));
            ii++;
        }
        while (!prev.empty()) {
    prev.pop();
}
        ii =heights.size()-1;
        for (auto i = heights.rbegin(); i != heights.rend(); ++i) {
    while(prev.empty()!=true && prev.top().second>= *i){
                prev.pop();
            }
            if(prev.empty()==true){
                ZtoA[ii]=make_pair(heights.size(),-1);
            }
            else{
                ZtoA[ii]=prev.top();
            }
            prev.push(make_pair(ii,*i));
            ii--;
}
         ii = 0;
        int maxo = INT_MIN;
    for (auto i = heights.begin(); i != heights.end(); ++i) {
        maxo = max(maxo,(ZtoA[ii].first-AtoZ[ii].first-1)*(*i));
        ii++;
    }
        return maxo ;
    }
};