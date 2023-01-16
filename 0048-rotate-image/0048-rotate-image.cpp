class Solution {
public:
    void sap(vector<vector<int>>& mat,int start, int end){
        for(int i = 0; i<mat.size();i++){
            swap(mat[start][i],mat[end][i]);
        }
    }
    void rotate(vector<vector<int>>& mat) {
        int start= 0 ;
        int end= mat.size()-1;
        while(start<=end){
            sap(mat,start,end);
            start++;
            end--;
        }
        for(int i = 0 ; i<mat.size();i++){
            for(int j= i ; j<mat.size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};