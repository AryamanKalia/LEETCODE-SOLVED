class Solution {
public:
    int helper(vector<vector<int>>& grid,int m , int n,vector<vector<int>>& t){
        if(m==1 && n==1)return grid[m-1][n-1];
        if(m==1){
            if(t[m][n]!=-1)return t[m][n];
            return t[m][n]=grid[m-1][n-1]+helper(grid,m,n-1,t);
        }
        if(n==1){
            if(t[m][n]!=-1)return t[m][n];
            return t[m][n]=grid[m-1][n-1]+helper(grid,m-1,n,t);
        }
        if(t[m][n]!=-1)return t[m][n];
        return t[m][n]=grid[m-1][n-1]+min(helper(grid,m,n-1,t),helper(grid,m-1,n,t));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> t(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return helper(grid,grid.size(),grid[0].size(),t);
        
    }
};