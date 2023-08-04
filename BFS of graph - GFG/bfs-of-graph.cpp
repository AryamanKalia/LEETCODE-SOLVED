//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
   vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs; // to store the traversal order
    vector<int> vis(V, 0); // to mark the visited nodes
    queue<int> q; // to store the nodes to be processed
    q.push(0); // start from node 0
    vis[0] = 1; // mark node 0 as visited
    while(!q.empty()) { // while the queue is not empty
        int node = q.front(); // get the front node of the queue
        q.pop(); // remove it from the queue
        bfs.push_back(node); // add it to the traversal order
        for(auto it : adj[node]) { // for each adjacent node of the current node
            if(!vis[it]) { // if it is not visited
                q.push(it); // push it to the queue
                vis[it] = 1; // mark it as visited
            }
        }
    }
    return bfs; // return the traversal order
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends