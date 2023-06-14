class Solution {
public:
    int maxArea(vector<int>& height) {
        int less=0; 
        int more=height.size()-1;
        int ans=INT_MIN;
        while(less<more){
            ans=max(ans,min(height[less],height[more])*(more-less));
            if(height[less]<=height[more]){
                less++;
            }
            else if(height[less]>height[more]){
                more--;
            }
        }
                    return ans;
    }
};