class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>nextbigg(height.size(),0);
        vector<int>prevbigg(height.size(),0);
        int nextbig=INT_MIN;
        int prevbig=INT_MIN;
        for(int i = height.size()-1;i>=0;i--){
            nextbigg[i]=nextbig=max(nextbig,height[i]);
        }
        for(int i=0;i<height.size();i++){
         prevbigg[i]=prevbig=max(prevbig,height[i]);
        }
        int sum= 0;
        for(int i = 0 ; i<height.size();i++)
        if(min(prevbigg[i],nextbigg[i])>height[i]){
            sum+=min(prevbigg[i],nextbigg[i])-height[i];
        }
        return sum;
    }
};