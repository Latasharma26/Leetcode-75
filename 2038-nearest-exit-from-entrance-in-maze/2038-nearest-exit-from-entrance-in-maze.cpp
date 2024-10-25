#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;

        // Mark the entrance as visited by changing its value to '+'
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                // Check if this cell is an exit
                if ((x != entrance[0] || y != entrance[1]) && (x == 0 || x == m - 1 || y == 0 || y == n - 1)) {
                    return steps;
                }

                // Explore the four possible directions
                for (const auto& [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;
                    // Check bounds and if it's an empty cell
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == '.') {
                        maze[newX][newY] = '+'; // Mark as visited
                        q.push({newX, newY});
                    }
                }
            }
            steps++; // Increment the step count after exploring the current level
        }
        
        return -1; // No exit found
    }
};
