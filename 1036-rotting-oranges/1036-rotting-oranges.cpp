#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        int minutes = 0;

        // Initial setup: enqueue rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Add rotten orange to the queue
                } else if (grid[i][j] == 1) {
                    freshCount++; // Count fresh oranges
                }
            }
        }

        // Directions for 4-way movement
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS process
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                // Explore the four possible directions
                for (const auto& [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;
                    // Check if the new position is valid
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        // Rot the fresh orange
                        grid[newX][newY] = 2;
                        freshCount--; // Decrease the count of fresh oranges
                        q.push({newX, newY}); // Add new rotten orange to the queue
                    }
                }
            }
            minutes++; // Increment the minute count after processing the current level
        }

        // If there are still fresh oranges left, return -1
        return freshCount == 0 ? minutes : -1;
    }
};
