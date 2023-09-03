//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool adj[101][101],int i,int c,int n,vector<int> &vis){
        for(int j=0;j<n;j++) if(i!=j and adj[i][j] and vis[j] == c) return false;
        return true;
    }
    
    bool dfs(bool adj[101][101],int n,vector<int> &vis,int m,int i){
        if(i == n) return true;
        for(int c=1;c<=m;c++){
            vis[i]=c;
            if(isSafe(adj,i,c,n,vis))
                if(dfs(adj,n,vis,m,i+1)) return true;
        }
        vis[i] = 0; // backtracking
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n,0);
        return dfs(graph,n,vis,m,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends