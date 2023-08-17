class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // Memoization table
        
        return editDistance(word1, word2, m, n, memo);
    }
    
    int editDistance(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0) return j; // If word1 is empty, we need to insert all characters from word2
        if (j == 0) return i; // If word2 is empty, we need to delete all characters from word1
        
        if (memo[i][j] != -1) {
            return memo[i][j]; // Return memoized result if available
        }
        
        if (word1[i - 1] == word2[j - 1]) {
            return memo[i][j] = editDistance(word1, word2, i - 1, j - 1, memo);
        } else {
            int insertOp = editDistance(word1, word2, i, j - 1, memo) + 1;
            int deleteOp = editDistance(word1, word2, i - 1, j, memo) + 1;
            int replaceOp = editDistance(word1, word2, i - 1, j - 1, memo) + 1;
            return memo[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }
};
