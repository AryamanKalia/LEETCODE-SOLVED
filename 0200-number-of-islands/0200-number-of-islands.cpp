class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row , int col , vector<vector<int>>& visited){
        if(row==grid.size()||col == grid[0].size()) return ;
        visited[row][col] = 1;
        if(row+1<grid.size() && grid[row+1][col]=='1' && visited[row+1][col]==-1) dfs(grid,row+1,col,visited);
        if(row-1>=0 && grid[row-1][col]=='1' && visited[row-1][col]==-1) dfs(grid,row-1,col,visited);
        if(col+1<grid[0].size() && grid[row][col+1]=='1' && visited[row][col+1]==-1) dfs(grid,row,col+1,visited);
        if(col-1>=0 && grid[row][col-1]=='1' && visited[row][col-1]==-1) dfs(grid,row,col-1,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int connected=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i = 0 ; i<grid.size();i++){
            for(int j = 0 ; j<grid[0].size();j++){
                if(visited[i][j]==-1 && grid[i][j]=='1'){
                    connected++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return connected;
    }
};
