class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& path, vector<vector<int>>& adj,stack<int> &st) {
        visited[node] = 1;
        path[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                if (dfs(neighbor, visited, path, adj,st))
                    return true;
            } else if (path[neighbor] == 1) {
                return true;  // Cycle detected
            }
        }
        st.push(node);
        path[node] = 0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);
        stack<int> st;
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, visited, path, adj,st))
                    return {};  // Cycle detected, return empty vector
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0)
                dfs(i, visited, path, adj,st);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
