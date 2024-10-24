class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap; // To count occurrences of each number
        unordered_set<int> uniqueCounts; // To store unique counts
        
        // Count the occurrences of each number
        for (int num : arr) {
            countMap[num]++;
        }
        
        // Check if counts are unique
        for (const auto& entry : countMap) {
            int count = entry.second; // Get the count of occurrences
            
            // If the count is already in the set, return false
            if (uniqueCounts.find(count) != uniqueCounts.end()) {
                return false;
            }
            uniqueCounts.insert(count); // Otherwise, insert the count
        }
        
        return true; // All counts are unique
    }
};