class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Step 1: Build the graph
        vector<vector<pair<int, bool>>> graph(n); // bool indicates if the road needs to be reversed
        
        for (const auto& conn : connections) {
            int a = conn[0];
            int b = conn[1];
            graph[a].push_back({b, true});  // a -> b (needs reverse)
            graph[b].push_back({a, false}); // b -> a (no reverse needed)
        }
        
        // Step 2: DFS to count the number of roads that need to be reversed
        vector<bool> visited(n, false);
        return dfs(0, graph, visited);
    }
    
private:
    int dfs(int city, vector<vector<pair<int, bool>>>& graph, vector<bool>& visited) {
        visited[city] = true;  // Mark the current city as visited
        int changes = 0; // Counter for roads to reverse
        
        for (const auto& [neighbor, needsReverse] : graph[city]) {
            if (!visited[neighbor]) { // If neighbor city hasn't been visited
                changes += needsReverse ? 1 : 0; // Count if this edge needs reversing
                changes += dfs(neighbor, graph, visited); // Recurse to neighbor
            }
        }
        
        return changes; // Return total changes needed
    }
};
