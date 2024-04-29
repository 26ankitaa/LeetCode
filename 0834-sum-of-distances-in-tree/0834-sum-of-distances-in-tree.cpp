class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> count(n, 1);
        vector<int> ans(n, 0);

        // Create adjacency list representation of the tree
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Post-order DFS to calculate count and ans for each node
        postOrderDFS(graph, count, ans, 0, -1);

        // Pre-order DFS to update ans for each node
        preOrderDFS(graph, count, ans, 0, -1);

        return ans;
    }

private:
    void postOrderDFS(const vector<vector<int>>& graph, vector<int>& count, vector<int>& ans, int node, int parent) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                postOrderDFS(graph, count, ans, neighbor, node);
                count[node] += count[neighbor];
                ans[node] += ans[neighbor] + count[neighbor];
            }
        }
    }

    void preOrderDFS(const vector<vector<int>>& graph, const vector<int>& count, vector<int>& ans, int node, int parent) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                ans[neighbor] = ans[node] - count[neighbor] + count.size() - count[neighbor];
                preOrderDFS(graph, count, ans, neighbor, node);
            }
        }
        
    }
};