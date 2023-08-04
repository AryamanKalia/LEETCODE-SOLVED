//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   vector<int> abc;
    void dfss(int v, vector<int> adj[],vector<int>& visited,int i){
        visited[i]=0;
        abc.push_back(i);
        for(int ii = 0 ; ii<adj[i].size();ii++){
            if(visited[adj[i][ii]]){
                dfss(v,adj,visited,adj[i][ii]);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        abc.clear();
        vector<int> visited(V,1);
        dfss(V,adj,visited,0);
    return abc;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends