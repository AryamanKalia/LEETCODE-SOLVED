//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool sst(pair<int,int> a , pair<int,int>b){
        double aa = (double)a.first/(double)a.second;
        double bb = (double)b.first/(double)b.second;
        return bb<aa;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>> abc; 
        for(int i = 0 ; i < n ;i++){
            abc.push_back(make_pair(arr[i].value,arr[i].weight));
        }
        sort(abc.begin(),abc.end(),sst);
        double profit=0.0;
        int i = 0 ; 
        while (W>0 && i<n){
            if(W>abc[i].second){
                profit= profit+ abc[i].first;
                W-=abc[i].second;
            }
            else{
                profit= profit+ ((double)abc[i].first/(double)abc[i].second)*W;
                W-=W;
            }
            i++;
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends