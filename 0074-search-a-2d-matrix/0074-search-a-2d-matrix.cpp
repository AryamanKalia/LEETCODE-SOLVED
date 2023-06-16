class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0 ; 
        int high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int mid1;int mid2;
            mid1=(mid/matrix[0].size());
            mid2=mid%matrix[0].size();
            if(matrix[mid1][mid2]==target){
                return true;
            }
            else if(matrix[mid1][mid2]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};