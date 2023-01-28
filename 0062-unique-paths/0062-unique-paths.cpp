class Solution {
public:
    vector<vector<int> > arr;
    int solve(int m, int n, int i, int j){
        if(i==m-1 && j==n-1)    return 1;
        if(i>m-1 || j>n-1)  return 0;
        if(arr[i][j]!=-1)    return arr[i][j];
        return arr[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
    }
    
    int uniquePaths(int m, int n) {
        arr.resize(m, vector<int>(n, -1));
        return solve(m, n, 0, 0);
    }
};