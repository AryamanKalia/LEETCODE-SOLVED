//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int l = 0 ;
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= 2*n-1 ;j++) {
                if(((j >= n -l) &&( j<=n+l))){
                    cout<<"*";
                }
                else
                cout<<" ";
            }
            cout<<""<<endl;
            l++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends