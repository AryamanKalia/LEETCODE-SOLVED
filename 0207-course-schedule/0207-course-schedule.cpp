class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited, vector<int>& recStack) {
        visited[node] = 1;
        recStack[node] = 1;
        for(int i = 0; i < adj[node].size(); i++) {
            int nextNode = adj[node][i];
            if(!visited[nextNode]) {
                if(dfs(adj, nextNode, visited, recStack)) return true;
            }
            else if(recStack[nextNode]) return true;
        }
        recStack[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses);
        vector<int> recStack(numCourses);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfs(adj, i, visited, recStack)) return false;
            }
        }
        return true;
    }
};
