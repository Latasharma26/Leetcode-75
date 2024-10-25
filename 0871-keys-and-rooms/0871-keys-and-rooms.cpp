class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        // Mark the current room as visited
        visited[room] = true;
        
        // Visit all rooms that we have keys for
        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms, visited);  // Recursive DFS call
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();  // Number of rooms
        vector<bool> visited(n, false);  // To track visited rooms
        
        dfs(0, rooms, visited);  // Start the DFS from room 0
        
        // Check if all rooms were visited
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};
