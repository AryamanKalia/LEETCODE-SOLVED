class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row;
        row.resize(9);
        vector<unordered_set<char>> col;
        col.resize(9);
        vector<vector<unordered_set<char>>>block;
        block.resize(3);
        for(auto ii = block.begin(); ii!=block.end();ii++){
            ii->resize(3);
        }
        for(int i = 0 ; i < board.size();i++){
            for(int j = 0 ; j<board[i].size();j++){
                //first rows 
                if(board[i][j]!='.'){
                if(row[i].find(board[i][j])==row[i].end()){
                    row[i].insert(board[i][j]);
                }
                    else {return false;}
                    if(col[j].find(board[i][j])==col[j].end()){
                        col[j].insert(board[i][j]);
                    }
                    else {return false;}
                    if(block[i/3][j/3].find(board[i][j])==block[i/3][j/3].end()){
                       block[i/3][j/3].insert(board[i][j]);
                    }
                    else{return false;}
            }
        }
    }
        return true;
    }
};