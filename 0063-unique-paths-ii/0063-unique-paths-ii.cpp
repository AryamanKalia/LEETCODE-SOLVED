class Solution {
public:
    vector<vector<int> > arr;
     int solve(int m, int n, int i, int j,vector<vector<int>>& obstacle){
        if(i==m-1 && j==n-1 && obstacle[i][j]!=1)    return 1;
        if(i>m-1 || j>n-1 || obstacle[i][j]==1)  return 0;
        if(arr[i][j]!=-1)    return arr[i][j];
        return arr[i][j] = solve(m, n, i+1, j,obstacle) + solve(m, n, i, j+1,obstacle);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        arr.resize(m, vector<int>(n, -1));
        return solve(m, n, 0, 0,obstacleGrid);
        
    }
};