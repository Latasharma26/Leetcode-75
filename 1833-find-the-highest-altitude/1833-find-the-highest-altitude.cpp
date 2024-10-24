class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;  // Starting at altitude 0
        int maxAltitude = 0;       // Highest altitude encountered

        // Iterate through the gain array
        for (int g : gain) {
            currentAltitude += g;   // Update the current altitude
            maxAltitude = max(maxAltitude, currentAltitude); // Update the maximum altitude
        }

        return maxAltitude;  // Return the highest altitude found
    }
};