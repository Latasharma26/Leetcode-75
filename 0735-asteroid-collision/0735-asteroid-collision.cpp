
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> asteroidCollision(vector<int>& asteroids) const {
        
        int index = -1;
        for (const auto& currentAsteroid : asteroids) {

            bool currentAsteroidIsUndestroyed = true;
            while (currentAsteroidIsUndestroyed && index >= 0 && asteroids[index] > 0 && currentAsteroid < 0) {
                currentAsteroidIsUndestroyed = currentAsteroid + asteroids[index] < 0;
                if (currentAsteroid + asteroids[index] <= 0) {
                    --index;
                }
            }
            if (currentAsteroidIsUndestroyed) {
                asteroids[++index] = currentAsteroid;
            }
        }

        return vector<int>(asteroids.begin(), asteroids.begin() + index + 1);
    }
};