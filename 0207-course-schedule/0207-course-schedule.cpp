#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to represent the directed graph
        vector<vector<int>> adj_list(numCourses);
        // Create an indegree list to keep track of the number of incoming edges for each node
        vector<int> indegree(numCourses);
        // Add the edges to the adjacency list and update the indegree list
        for (auto& p : prerequisites) {
            adj_list[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        // Create a queue to store the nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // Perform a topological sort
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj_list[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        // Check if all nodes have been visited (indegree is 0 for all nodes)
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};