//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.first < b.first; // Sort based on departure times
    }
    
    int findPlatform(int arr[], int dep[], int n){
        vector<pair<int,int>> ary; // Vector of pairs to store arrival and departure times
        for(int i = 0 ; i < n ; i++){
            ary.push_back({arr[i], dep[i]}); // Store arrival and departure times as pairs
        }
        sort(ary.begin(), ary.end(), compare); // Sort the pairs based on departure times
        int send = ary[0].second; // Store the departure time of the first train
        vector<int> ab; // Vector to store departure times of trains on the platforms
        ab.push_back(send); // Initialize with the departure time of the first train
        for(int i = 1 ; i < n ; i++){
            bool aaa = false; // Flag to track if the train can be accommodated on an existing platform
            for(int j = 0 ; j < ab.size(); j++){
                if(ary[i].first > ab[j]){ // If arrival time of current train is greater than departure time of train on platform
                    aaa = true; // Set flag to true
                    ab[j] = ary[i].second; // Update departure time of train on platform
                    break;
                }
            }
            if(aaa == false){ // If flag is false, no existing platform can accommodate the train
                ab.push_back(ary[i].second); // Add new platform with departure time of current train
            }
        }
        return ab.size(); // Return the size of the vector representing departure times of trains on the platforms, i.e., minimum number of platforms required
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends