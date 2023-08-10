class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& t) {
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        
        if (t[row][col] != -1) {
            return t[row][col];
        }
        
        int left = helper(row + 1, col, triangle, t);
        int right = helper(row + 1, col + 1, triangle, t);
        
        t[row][col] = triangle[row][col] + min(left, right);
        return t[row][col];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> t(triangle.size(), vector<int>(triangle.size(), -1));
        return helper(0, 0, triangle, t);
    }
};
