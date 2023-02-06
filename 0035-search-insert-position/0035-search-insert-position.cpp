class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int low = 0 ;
        int high = arr.size()-1;
        int mid;
        if(arr[low]<=arr[high]){
            while(low<=high){
                 mid=low + (high-low)/2;
                if(arr[mid]==target){return mid;}
                if(arr[mid]<target){low=mid+1;}
                if(arr[mid]>target){high=mid-1;}
            }
        }
        if(arr[mid]<target)return mid+1;
        else return mid;
    }
};