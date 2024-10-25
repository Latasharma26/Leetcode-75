#include <vector>
#include <algorithm> // For sort and lower_bound

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::vector<int> result(spells.size(), 0);
        std::sort(potions.begin(), potions.end()); // Sort potions for binary search

        for (int i = 0; i < spells.size(); ++i) {
            // Calculate the minimum potion strength required for a successful pair
            long long minPotion = (success + spells[i] - 1) / spells[i]; // Use long long to avoid overflow
            
            // Use lower_bound to find the first potion >= minPotion
            auto it = std::lower_bound(potions.begin(), potions.end(), minPotion);
            result[i] = potions.end() - it; // Count successful potions
        }
        
        return result;
    }
};
