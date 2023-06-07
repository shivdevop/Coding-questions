class Solution {
public:
    bool dfsDetectCycle(int node, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>>& adj) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                if (dfsDetectCycle(neighbor, visited, pathVisited, adj))
                    return true;
            } else if (pathVisited[neighbor] == 1) {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfsDetectCycle(i, visited, pathVisited, adj))
                    return false;
            }
        }

        return true;
    }
};
