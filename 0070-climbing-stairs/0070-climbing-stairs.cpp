class Solution {
public:
    int climb(int n,vector<int>& t){
        if(n== 0|| n==1 ||n==2){return n;}
        if(n<0)return 0;
        if(t[n]!=-1)return t[n];
        return t[n]=climb(n-1,t)+climb(n-2,t);
    }
    int climbStairs(int n) {
        vector<int>t(n+1,-1);
        return climb(n,t);
    }
};