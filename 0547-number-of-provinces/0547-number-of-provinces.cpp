class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;  // Mark the city as visited
        
        // Visit all directly connected cities
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);  // Recursive DFS call
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();  // Number of cities
        vector<bool> visited(n, false);  // To track visited cities
        int provinces = 0;  // Province count
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {  // If the city hasn't been visited
                dfs(i, isConnected, visited);  // Start a new DFS traversal
                provinces++;  // Increment province count
            }
        }
        
        return provinces;  // Return the total number of provinces
    }
};
