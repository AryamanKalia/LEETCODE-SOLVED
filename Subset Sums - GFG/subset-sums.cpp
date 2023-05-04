//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> abc;
    void subsetSum(vector<int> arr, int N ,int k,int sum){
        if(k==N){
            abc.push_back(sum);
            return;
        }
        subsetSum(arr, N , k+1 , sum+arr[k]);
        subsetSum(arr , N , k+1 , sum);
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
     subsetSum(arr,N,0,0);
     sort(abc.begin(),abc.end());
     return abc;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends