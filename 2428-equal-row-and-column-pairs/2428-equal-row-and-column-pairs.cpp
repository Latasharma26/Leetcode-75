#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowCount;
        int n = grid.size();
        
        // Step 1: Count rows
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += to_string(grid[i][j]) + ",";
            }
            rowCount[row]++;
        }

        int count = 0;

        // Step 2: Check columns against row counts
        for (int j = 0; j < n; j++) {
            string col = "";
            for (int i = 0; i < n; i++) {
                col += to_string(grid[i][j]) + ",";
            }
            // Step 3: Add to count if column matches any row
            count += rowCount[col];
        }
        
        return count;
    }
};
