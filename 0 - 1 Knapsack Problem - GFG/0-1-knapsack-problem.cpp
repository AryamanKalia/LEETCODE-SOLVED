//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int getans(int w , int idx , int wt[] , int val[] , int n ,  vector<vector<int>>&memo){
        if(idx<0) return 0;
        if(memo[idx][w] != -1) return memo[idx][w];
        int a = 0 ;
        if(w-wt[idx]>=0){
            a = val[idx]+getans(w-wt[idx],idx-1,wt,val,n,memo);
        }
        a = max(a,getans(w,idx-1,wt,val,n,memo));
        return memo[idx][w] = a;
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> memo(n, vector<int>(W+1,-1));
       return getans(W,n-1,wt,val,n-1,memo);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends